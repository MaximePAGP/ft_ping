/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_socket.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:15:40 by magrondi          #+#    #+#             */
/*   Updated: 2025/12/18 13:21:26 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/data.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>

void	create_socket(t_data *data)
{
	data->socket_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (data->socket_fd < 0)
	{
		perror("Socket creation failed");
		exit(EXIT_FAILURE);
	}
}
