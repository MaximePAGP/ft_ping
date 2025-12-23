/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:35:16 by magrondi          #+#    #+#             */
/*   Updated: 2025/12/23 21:46:59 by magrondi         ###   ########.fr       */
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

static	bool	is_dns(char *argv)
{
	size_t	i;

	i = 0;
	while (argv && i < strlen(argv))
	{
		if (isalpha(argv[i]))
			return (true);
		i ++;
	}
	return (false);
}

void	display_unknow_host(t_data *data);
void	display_invalid_address(t_data *data);

static	void	resolve_or_check_ip(t_data *data)
{
	struct addrinfo hints;
	struct addrinfo *res;
	struct sockaddr_in *addr_in;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_RAW;
	if (is_dns(data->input)) {
		if (getaddrinfo(data->input, NULL, &hints, &res) != 0)
			display_unknow_host(data);
		addr_in = (struct sockaddr_in *)res->ai_addr;
		memcpy(data->dns_infos, res, sizeof(struct addrinfo));
		data->target_ip = addr_in->sin_addr;
		data->dns_infos->ai_addr = res->ai_addr;
		data->dns_infos->ai_addrlen = res->ai_addrlen;
	} else {
		if (inet_aton(data->input, &data->target_ip) == 0)
			display_invalid_address(data);
		data->dns_infos->ai_family = AF_INET;
		data->dns_infos->ai_socktype = SOCK_RAW;
		data->dns_infos->ai_addrlen = sizeof(struct sockaddr_in);
		data->dns_infos->ai_addr = (struct sockaddr *)&data->target_ip;
	}
}


void	display_executable(void);

void	manage_inputs(int argc, char **argv, t_data *data)
{
	if (argc == 1)
	{
		display_executable();
		exit(EXIT_FAILURE);
	}
	data->input = argv[1];
	handle_packets_flag(argc, argv, data);
	data->dns_infos = malloc(sizeof(struct addrinfo));
	if (!data->dns_infos) {
		write(STDERR_FILENO, "Malloc failed\n", 15);
		exit(EXIT_FAILURE);
	}
	data->dns_infos->ai_addr = malloc(sizeof(struct sockaddr_in));
	if (!data->dns_infos->ai_addr) {
		free(data->dns_infos);
		write(STDERR_FILENO, "Malloc failed for ai_addr\n", 26);
		exit(EXIT_FAILURE);
	}
	resolve_or_check_ip(data);
}
