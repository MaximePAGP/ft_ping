/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:35:16 by magrondi          #+#    #+#             */
/*   Updated: 2025/12/28 18:42:37 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/data.h"
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>

static	void	handle_packets_flag(int argc, char **argv, t_data *data)
{
	size_t	i;

	i = 2;
	while (i < (size_t)argc)
	{
		if (argv[i] && (
				strcmp(argv[i], "-?") == 0 || strcmp(argv[i], "-v") == 0))
		{
			data->flags.has_packets_errors = true;
			break ;
		}
		i ++;
	}
}

void	display_unknow_host(t_data *data);
void	display_invalid_address(t_data *data);

static void	resolve_or_check_ip(t_data *data)
{
	struct addrinfo		hints;
	struct addrinfo		*res;
	struct sockaddr_in	*addr_in;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_RAW;
	if (getaddrinfo(data->input, NULL, &hints, &res) != 0)
		display_unknow_host(data);
	data->dns_infos = res;
	addr_in = (struct sockaddr_in *)res->ai_addr;
	data->target_ip = addr_in->sin_addr;
}

void	display_executable(void);

void	manage_inputs(int argc, char **argv, t_data *data)
{
	if (argc == 1)
	{
		display_executable();
		exit(EXIT_FAILURE);
	}
	data->input = strdup(argv[1]);
	if (!data->input)
		exit(EXIT_FAILURE);
	handle_packets_flag(argc, argv, data);
	resolve_or_check_ip(data);
}
