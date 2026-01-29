/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_icmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 22:08:51 by magrondi          #+#    #+#             */
/*   Updated: 2026/01/29 21:43:20 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/data.h"
#include "../inc/icmp.h"
#include <stdint.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/ip.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

uint16_t checksum(uint16_t *addr, int len);
void display_icmp_packet(t_icmp *icmp_packet);
void display_packet_analytics(t_data *data, struct timeval *time_on_send,
							  struct timeval *time_on_recv, struct iphdr *ip_hdr, t_icmp *icmp);

static t_icmp create_icmp_packet(uint16_t seq)
{
	t_icmp icmp_packet;

	icmp_packet.type = ECHO_REQUEST;
	icmp_packet.code = 0;
	icmp_packet.checksum = 0;
	icmp_packet.id = htons(getpid() & 0xFFFF);
	icmp_packet.sequence = htons(seq);
	memset(icmp_packet.payload, 0, sizeof(icmp_packet.payload));
	icmp_packet.checksum = checksum((uint16_t *)&icmp_packet, sizeof(t_icmp));
	return (icmp_packet);
}

static void send_icmp_packet(t_data *data, t_icmp *icmp_packet)
{
	ssize_t resp;

	resp = sendto(data->socket_fd, icmp_packet, sizeof(t_icmp), 0,
				  data->dns_infos->ai_addr, data->dns_infos->ai_addrlen);
	if (resp < 0)
	{
		data->analytics.display_current_packet = false;
	}
	data->analytics.total_packets++;
}


static void received_ip_reply(t_data *data, uint16_t curr_sequence,
								struct timeval *time_on_recv, struct iphdr *ip_hdr,
								t_icmp *icmp)
{
	char			buffer[1024];
	struct iphdr	*ip;
	t_icmp			*icmp_reply;

	while (1) {
		memset(buffer, 0, sizeof(buffer));

		if (recvfrom(data->socket_fd, buffer, sizeof(buffer), 0, NULL, NULL) < 0) {
			if (errno == EAGAIN || errno == EWOULDBLOCK) {
				data->analytics.display_current_packet = false;
				return;
			}
			data->analytics.display_current_packet = false;
			return;
		}
	
		if (gettimeofday(time_on_recv, NULL) < 0) {
			data->analytics.display_current_packet = false;
			return;
		}

		ip = (struct iphdr *)buffer;
		icmp_reply = (t_icmp *)(buffer + (ip->ihl * 4));

		if (icmp_reply->type == ECHO_REQUEST) {
			continue;
		}
	
		if (ntohs(icmp_reply->id) != (getpid() & 0xFFFF)) {
			continue;
		}
	
		if (icmp_reply->type == ECHO_REPLY) {
			if (ntohs(icmp_reply->sequence) != curr_sequence) {
				continue;
			}
		}
	
		ip_hdr->ttl = ip->ttl;
		icmp->sequence = icmp_reply->sequence;
		icmp->type = icmp_reply->type;
		icmp->code = icmp_reply->code;
		icmp->id = icmp_reply->id;
	
		data->analytics.received_packets++;
		return;
	}
}


void handle_icmp(t_data *data)
{
	struct timeval	time_on_send;
	struct timeval	time_on_recv;
	struct iphdr	ip_hdr;
	uint16_t		sequence;
	t_icmp 			icmp_packet;

	sequence = 0;
	while (G_IS_RUNNING)
	{
		if ((u_int32_t)sequence >= UINT16_MAX)
			break;
		memset(&time_on_recv, 0, sizeof(struct timeval));
		memset(&time_on_send, 0, sizeof(struct timeval));
		memset(&ip_hdr, 0, sizeof(struct iphdr));

		data->analytics.display_current_packet = true;
		icmp_packet = create_icmp_packet(sequence);
		send_icmp_packet(data, &icmp_packet);
		if (gettimeofday(&time_on_send, NULL) < 0)
			data->analytics.display_current_packet = false;
		received_ip_reply(data, sequence, &time_on_recv, &ip_hdr, &icmp_packet);
		if (time_on_recv.tv_sec != 0 && time_on_recv.tv_usec != 0)
			display_packet_analytics(data, &time_on_send,
									 &time_on_recv, &ip_hdr, &icmp_packet);
		sequence++;
		// if (!data->analytics.display_current_packet)
				sleep(1);
	}
}
