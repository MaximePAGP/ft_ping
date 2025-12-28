/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_packet_analytics.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 14:53:43 by magrondi          #+#    #+#             */
/*   Updated: 2025/12/28 14:26:45 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/data.h"
#include "../inc/icmp.h"
#include <stdio.h>
#include <sys/time.h>
#include <netinet/ip.h>
#include <string.h>

double	calc_rtt(struct timeval *start, struct timeval *end);
void	extract_icmp(struct iphdr *ip_hdr, t_icmp *icmp);

void	display_packet_analytics(t_data *data, struct timeval *time_on_send,
	struct timeval *time_on_recv, struct iphdr *ip_hdr)
{
	double	rtt;
	t_icmp	icmp_packet;

	// if (!data->analytics.display_current_packet)
	// 	return ;
	memset(&icmp_packet, 0, sizeof(t_icmp));
	extract_icmp(ip_hdr, &icmp_packet);
	rtt = calc_rtt(time_on_send, time_on_recv);
	printf("%ld bytes from %s: icmp_seq=%ld ttl=%d time=%.2f ms\n",
		sizeof(t_icmp),
		data->input,
		data->analytics.total_packets,
		ip_hdr->ttl,
		rtt);
}
