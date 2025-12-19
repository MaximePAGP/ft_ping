/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imcp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:36:43 by magrondi          #+#    #+#             */
/*   Updated: 2025/12/18 22:20:08 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICMP_H
# define ICMP_H

typedef struct s_icmp
{
	uint8_t		type;
	uint8_t		code;
	uint16_t	checksum;
	uint16_t	id;
	uint16_t	sequence;
	uint32_t	rest;
}	t_icmp;

#endif