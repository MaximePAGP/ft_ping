/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_dns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:01:16 by magrondi          #+#    #+#             */
/*   Updated: 2025/12/01 11:13:51 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/data.h"

#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>


void    resolve_dns(char *input, t_data *data)
{
	struct addrinfo *res = NULL;
    getaddrinfo("google.com", "443", 0, &res);

	// printf("%s \n", (res));
	(void)data;
	(void)input;
}

