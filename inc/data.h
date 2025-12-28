/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:32:49 by magrondi          #+#    #+#             */
/*   Updated: 2025/12/28 14:53:58 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "flags.h"
# include "analytics.h"
# include <arpa/inet.h>
# include <netdb.h>
# include <signal.h>

extern volatile sig_atomic_t	G_IS_RUNNING;

typedef struct s_data
{
	struct in_addr		target_ip;
	struct addrinfo		*dns_infos;
	int					socket_fd;
	char				*input;
	t_flags				flags;
	t_analytics			analytics;
}	t_data;

#endif