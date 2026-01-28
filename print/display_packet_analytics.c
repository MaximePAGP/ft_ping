/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_packet_analytics.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 14:53:43 by magrondi          #+#    #+#             */
/*   Updated: 2026/01/28 21:18:35 by magrondi         ###   ########.fr       */
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
	struct timeval *time_on_recv, struct iphdr *ip_hdr, t_icmp *icmp)
{
	double	rtt;

	if (!data->analytics.display_current_packet)
		return ;
		
	rtt = calc_rtt(time_on_send, time_on_recv);
	if (data->flags.has_packets_errors) {
		printf("%ld bytes from %s: type = %d, code = %d\n",
			sizeof(t_icmp),
			data->input,
			icmp->type,
			icmp->code
		);
		return;
	}
	
	printf("%ld bytes from %s: icmp_seq=%d ttl=%d time=%.3f ms\n",
		sizeof(t_icmp),
		data->input,
		ntohs(icmp->sequence),
		ip_hdr->ttl,
		rtt
	);
}
