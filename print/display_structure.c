/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_structure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:32:34 by magrondi          #+#    #+#             */
/*   Updated: 2025/12/07 00:33:26 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/data.h"
#include <stdio.h>

void	display_structure(t_data *data)
{
	uint32_t	ip;

	ip = ntohl(data->target_ip.s_addr);
	printf("- input %s\n", data->input);
	printf("- ipv4 %d \n", data->target_ip.s_addr);
	printf("- ipv4 little endian %u.%u.%u.%u \n",
		(ip >> 24) & 0xFF,
		(ip >> 16) & 0xFF,
		(ip >> 8) & 0xFF,
		(ip) & 0xFF
		);
	ip = htonl(data->target_ip.s_addr);
	printf("- ipv4 big endian %u.%u.%u.%u \n",
		(ip >> 24) & 0xFF,
		(ip >> 16) & 0xFF,
		(ip >> 8) & 0xFF,
		(ip) & 0xFF
		);
	printf("- has flas %d \n", data->flags.has_packets_errors);
}
