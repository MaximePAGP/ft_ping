/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:35:16 by magrondi          #+#    #+#             */
/*   Updated: 2025/12/07 00:35:36 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "../inc/data.h"

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

void	display_executable(void);
void	resolve_dns(t_data *data);
void	check_ipv4(t_data *data);

void	manage_inputs(int argc, char **argv, t_data *data)
{
	if (argc == 1)
	{
		display_executable();
		exit(EXIT_FAILURE);
	}
	data->input = argv[1];
	handle_packets_flag(argc, argv, data);
	if (is_dns(argv[1]))
		resolve_dns(data);
	else
		check_ipv4(data);
}
