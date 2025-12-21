/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:38:25 by magrondi          #+#    #+#             */
/*   Updated: 2025/12/20 22:11:00 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

uint16_t	checksum(uint16_t *addr, int len)
{
	int			count;
	uint32_t	sum;
	uint16_t	answer;

	count = len;
	sum = 0;
	answer = 0;
	while (count > 1)
	{
		sum += *(addr++);
		count -= 2;
	}
	if (count > 0)
		sum += *(uint8_t *) addr;
	while (sum >> 16)
	{
		sum = (sum & 0xffff) + (sum >> 16);
	}
	answer = ~sum;
	return (answer);
}
