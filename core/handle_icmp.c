/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_icmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 22:08:51 by magrondi          #+#    #+#             */
/*   Updated: 2025/12/21 01:50:34 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/data.h"
#include "../inc/icmp.h"
#include <stdint.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h> 
#include <stdlib.h>
#include <stdio.h>

uint16_t	checksum(uint16_t *addr, int len);

t_icmp	create_icmp_packet(uint16_t seq)
{
	t_icmp	icmp_packet;

	icmp_packet.type = ECHO_REQUEST;
	icmp_packet.code = 0;
	icmp_packet.checksum = 0;
	icmp_packet.id = htons(getpid() & 0xFFFF);
	icmp_packet.sequence = htons(seq);
	memset(icmp_packet.payload, 0, sizeof(icmp_packet.payload));
	icmp_packet.checksum = checksum((uint16_t *) &icmp_packet, sizeof(t_icmp));
	return (icmp_packet);
}

void	send_icmp_packet(t_data *data, t_icmp *icmp_packet)
{
	ssize_t	resp;

	resp = sendto(data->socket_fd, icmp_packet, sizeof(t_icmp), 0,
			data->dns_infos->ai_addr, data->dns_infos->ai_addrlen);
	if (resp < 0)
	{
		close(data->socket_fd);
		perror("sendto failed");
		exit(EXIT_FAILURE);
	}
}

// 3receive reply
// 4calculate rtt 
//5print analytics
void	handle_icmp(t_data *data)
{
	uint16_t	sequence;
	t_icmp		icmp_packet;

	sequence = 0;
	while (data->is_running)
	{
		icmp_packet = create_icmp_packet(sequence);
		send_icmp_packet(data, &icmp_packet);
		sequence ++;
	}
}
