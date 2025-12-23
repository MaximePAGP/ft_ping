/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_invalid_inputs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 21:24:14 by magrondi          #+#    #+#             */
/*   Updated: 2025/12/23 21:33:15 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/data.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void	display_unknow_host(t_data *data)
{
	free(data->dns_infos->ai_addr);
	free(data->dns_infos);
	write(STDERR_FILENO, "ping: unknown host\n", 20);
	exit(EXIT_FAILURE);	
}


void	display_invalid_address(t_data *data)
{
	free(data->dns_infos->ai_addr);
	free(data->dns_infos);
	write(STDERR_FILENO, "ping: ", 7);
	write(STDERR_FILENO, data->input, strlen(data->input));
	write(STDERR_FILENO, ": Name or service not known", 28);
	exit(EXIT_FAILURE);
}
