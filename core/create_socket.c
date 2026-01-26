/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_socket.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:15:40 by magrondi          #+#    #+#             */
/*   Updated: 2026/01/26 19:35:12 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/data.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>

void	create_socket(t_data *data)
{
	struct timeval timeout;

	data->socket_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (data->socket_fd < 0)
	{
		perror("Socket creation failed");
		exit(EXIT_FAILURE);
	}
	timeout.tv_sec = 1;
	timeout.tv_usec = 0;
	if (setsockopt(data->socket_fd, SOL_SOCKET, SO_RCVTIMEO,
		&timeout, sizeof(timeout)) != 0) {
		perror("Socket options failed");
		close(data->socket_fd);
		exit(EXIT_FAILURE);
	}
}
