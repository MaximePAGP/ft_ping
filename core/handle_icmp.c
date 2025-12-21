/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_icmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 22:08:51 by magrondi          #+#    #+#             */
/*   Updated: 2025/12/21 17:20:39 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/data.h"
#include "../inc/icmp.h"
#include <stdint.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>

uint16_t	checksum(uint16_t *addr, int len);

static	t_icmp	create_icmp_packet(uint16_t seq)
{
	t_icmp	icmp_packet;

	icmp_packet.type = ECHO_REQUEST;
	icmp_packet.code = 0;
	icmp_packet.checksum = 0;
	icmp_packet.id = htons(getpid() & 0xFFFF);
	icmp_packet.sequence = htons(seq);
	memset(icmp_packet.payload, 0, sizeof(icmp_packet.payload));
	icmp_packet.checksum = checksum((uint16_t *)&icmp_packet, sizeof(t_icmp));
	return (icmp_packet);
}

static	void	send_icmp_packet(t_data *data, t_icmp *icmp_packet)
{
	ssize_t	resp;

	resp = sendto(data->socket_fd, icmp_packet, sizeof(t_icmp), 0,
			data->dns_infos->ai_addr, data->dns_infos->ai_addrlen);
	if (resp < 0)
	{
		data->analytics.display_current_packet = false;
	}
	data->analytics.total_packets ++;
}

static	void	received_icmp_reply(t_data *data, struct timeval *time_on_send,
	uint16_t curr_sequence)
{
	char	buffer[1024];
	t_icmp	*icmp_reply;

	if (recvfrom(data->socket_fd, buffer, sizeof(buffer), 0,
			data->dns_infos->ai_addr, &data->dns_infos->ai_addrlen) < 0)
	{
		data->analytics.display_current_packet = false;
		return ;
	}
	data->analytics.received_packets ++;
	icmp_reply = (t_icmp *)buffer;
	if (icmp_reply->type != ECHO_REPLY)
		return ;
	if (ntohs(icmp_reply->sequence) != curr_sequence)
		return ;
	(void)time_on_send;
}

// 4calculate rtt
// 5print analytics
void	handle_icmp(t_data *data)
{
	struct timeval	time_on_send;
	uint16_t		sequence;
	t_icmp			icmp_packet;

	sequence = 0;
	while (data->is_running)
	{
		data->analytics.display_current_packet = true;
		icmp_packet = create_icmp_packet(sequence);
		send_icmp_packet(data, &icmp_packet);
		if (gettimeofday(&time_on_send, NULL))
		{
			perror("Func *Handle_icmp: gettimeofday failed");
			close(data->socket_fd);
			exit(EXIT_FAILURE);
		}
		received_icmp_reply(data, &time_on_send, sequence);
		sequence++;
	}
}
