/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_icmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 22:08:51 by magrondi          #+#    #+#             */
/*   Updated: 2026/01/28 18:06:37 by magrondi         ###   ########.fr       */
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

uint16_t checksum(uint16_t *addr, int len);
void display_icmp_packet(t_icmp *icmp_packet);
void display_packet_analytics(t_data *data, struct timeval *time_on_send,
							  struct timeval *time_on_recv, struct iphdr *ip_hdr);

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
							  struct timeval *time_on_recv, struct iphdr *ip_hdr)
{
	char buffer[1024];
	t_icmp *icmp_packet;

	memset(buffer, 0, sizeof(buffer));
	if (recvfrom(data->socket_fd, buffer, sizeof(buffer), 0,
				 data->dns_infos->ai_addr, &data->dns_infos->ai_addrlen) < 0) {
		data->analytics.display_current_packet = false;
		return;
	}
	
	if (gettimeofday(time_on_recv, NULL) < 0) {
		data->analytics.display_current_packet = false;
		return;
	}
	
	data->analytics.received_packets++;
	ip_hdr->ttl = (int)((struct iphdr *)buffer)->ttl;
	icmp_packet = (t_icmp *)(buffer + (ip_hdr->ihl * 4));
	printf("youpi %d\n", icmp_packet->sequence);
		
	if (ntohs(icmp_packet->id) != (getpid() & 0xFFFF)) {
		data->analytics.display_current_packet = false;
		return;
	}
	if (ntohs(icmp_packet->sequence) != curr_sequence) 	{
		data->analytics.display_current_packet = false;
		return;
	}
}

void handle_icmp(t_data *data)
{
	struct timeval	time_on_send;
	struct timeval	time_on_recv;
	struct iphdr	ip_hdr;
	uint16_t		sequence;
	t_icmp 			icmp_packet_sent;

	sequence = 0;
	while (G_IS_RUNNING)
	{
		if ((u_int32_t)sequence >= UINT16_MAX)
			break;
		memset(&time_on_recv, 0, sizeof(struct timeval));
		memset(&time_on_send, 0, sizeof(struct timeval));
		memset(&ip_hdr, 0, sizeof(struct iphdr));

		data->analytics.display_current_packet = true;
		icmp_packet_sent = create_icmp_packet(sequence);
		send_icmp_packet(data, &icmp_packet_sent);
		if (gettimeofday(&time_on_send, NULL) < 0)
			data->analytics.display_current_packet = false;
		received_ip_reply(data, sequence, &time_on_recv, &ip_hdr);
		if (time_on_recv.tv_sec != 0 && time_on_recv.tv_usec != 0)
			display_packet_analytics(data, &time_on_send,
									 &time_on_recv, &ip_hdr);
		sequence++;
		// if (!data->analytics.display_current_packet)
				sleep(1);
	}
}
