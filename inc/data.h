/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:32:49 by magrondi          #+#    #+#             */
/*   Updated: 2025/12/02 16:24:01 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H


# include "flags.h"
# include <arpa/inet.h>

typedef struct s_data
{
	struct	in_addr		target_ip;
	struct	addrinfo	*dns_infos;
	char				*input;
	t_flags				flags;
}	t_data;

#endif