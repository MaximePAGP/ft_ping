/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rtt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 14:25:25 by magrondi          #+#    #+#             */
/*   Updated: 2025/12/24 14:26:29 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

double	calc_rtt(struct timeval *start, struct timeval *end)
{
	double	rtt;

	rtt = (end->tv_sec - start->tv_sec) * 1000.0;
	rtt += (end->tv_usec - start->tv_usec) / 1000.0;
	return (rtt);
}
