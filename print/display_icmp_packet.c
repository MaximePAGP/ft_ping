/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_icmp_packet.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:25:01 by magrondi          #+#    #+#             */
/*   Updated: 2025/12/23 09:21:30 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/icmp.h"
#include <stdio.h>
#include <arpa/inet.h>

void	display_icmp_packet(t_icmp *icmp_packet)
{
	printf("--------ICMP Packet--------\n");
	printf("type : %d \n", icmp_packet->type);
	printf("code : %d \n", icmp_packet->code);
	printf("checksum : 0x%04x\n", ntohs(icmp_packet->checksum));
	printf("id : %d\n", icmp_packet->id);
	printf("sequence : %d\n", icmp_packet->sequence);
	printf("---------------------------\n");
}
