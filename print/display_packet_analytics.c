/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_packet_analytics.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:33:04 by magrondi          #+#    #+#             */
/*   Updated: 2025/12/27 10:24:46 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/data.h"
#include "../inc/icmp.h"
#include <stdio.h>
#include <sys/time.h>

double	calc_rtt(struct timeval *start, struct timeval *end);

void	display_packet_analytics(t_data *data ,struct timeval *time_on_send,
	struct timeval *time_on_recv, t_icmp *icmp_packet)
{
	double	rtt;

	if (!data->analytics.display_current_packet)
		return ;
	rtt = calc_rtt(time_on_send, time_on_recv);
	printf("%ld bytes from %s: icmp_seq=%d ttl=%d time=%.2f ms\n",
		sizeof(t_icmp),
		data->input,
		ntohs(icmp_packet->sequence),
		0,
		rtt);
}