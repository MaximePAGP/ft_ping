/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:37:06 by magrondi          #+#    #+#             */
/*   Updated: 2025/12/21 12:17:55 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/data.h"
#include "./inc/flags.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	manage_inputs(int argc, char **argv, t_data *data);
void	display_structure(t_data *data);
void	create_socket(t_data *data);
void	handle_icmp(t_data *data);

int	main(int argc, char **argv)
{
	t_data	data;

	memset(&data, 0, sizeof(t_data));
	data.input = NULL;
	manage_inputs(argc, argv, &data);
	create_socket(&data);
	handle_icmp(&data);
	display_structure(&data);
	return (EXIT_SUCCESS);
}
