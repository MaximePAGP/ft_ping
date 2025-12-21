/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   icmp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:36:43 by magrondi          #+#    #+#             */
/*   Updated: 2025/12/21 01:40:34 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICMP_H
# define ICMP_H

# ifndef ECHO_REQUEST
#  define ECHO_REQUEST 8
# endif

# ifndef ECHO_REPLY
#  define ECHO_REPLY 0
# endif

# ifndef UNREACHABLE
#  define UNREACHABLE 3
# endif

typedef struct s_icmp
{
	uint8_t		type;
	uint8_t		code;
	uint16_t	checksum;
	uint16_t	id;
	uint16_t	sequence;
	uint8_t		payload[56];
}	t_icmp;

#endif
