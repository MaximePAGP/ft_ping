/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analytics.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:27:58 by magrondi          #+#    #+#             */
/*   Updated: 2026/01/28 18:00:22 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANALYTICS_H
# define ANALYTICS_H

# include <stdbool.h>
# include <unistd.h>

typedef struct s_analytics
{
	bool			display_current_packet;
	size_t			total_packets;
	size_t			received_packets;
}	t_analytics;

#endif