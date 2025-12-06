/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_dns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:40:18 by magrondi          #+#    #+#             */
/*   Updated: 2025/12/07 00:35:15 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/data.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void	resolve_dns(t_data *data)
{
	struct addrinfo		hints;
	struct addrinfo		*res;
	struct sockaddr_in	*addr_in;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	if (getaddrinfo(data->input, NULL, &hints, &res) != 0)
	{
		write(STDERR_FILENO, "ping: unknown host\n", 20);
		exit(EXIT_FAILURE);
	}
	addr_in = (struct sockaddr_in *)res->ai_addr;
	data->target_ip = addr_in->sin_addr;
	freeaddrinfo(res);
}
