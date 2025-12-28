/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:37:06 by magrondi          #+#    #+#             */
/*   Updated: 2025/12/28 18:54:33 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/data.h"
#include "./inc/flags.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

void	manage_inputs(int argc, char **argv, t_data *data);
void	display_structure(t_data *data);
void	display_analytics(t_data *data);
void	create_socket(t_data *data);
void	handle_icmp(t_data *data);
void	clean(t_data *data);
void	catch_signals(void);

volatile sig_atomic_t	G_IS_RUNNING;

int	main(int argc, char **argv)
{
	t_data	data;

	catch_signals();
	memset(&data, 0, sizeof(t_data));
	G_IS_RUNNING = 1;
	data.input = NULL;
	manage_inputs(argc, argv, &data);
	create_socket(&data);
	handle_icmp(&data);
	display_analytics(&data);
	clean(&data);
	return (EXIT_SUCCESS);
}
