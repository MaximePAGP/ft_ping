/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:37:06 by magrondi          #+#    #+#             */
/*   Updated: 2026/01/26 20:35:59 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/data.h"
#include "./inc/flags.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void manage_inputs(int argc, char **argv, t_data *data);
void display_structure(t_data *data);
void display_analytics(t_data *data);
void create_socket(t_data *data);
void handle_icmp(t_data *data);
void clean(t_data *data);
void catch_signals(void);

volatile sig_atomic_t G_IS_RUNNING;

int main(int argc, char **argv)
{
	t_data data;
	struct timeval time = {};

	memset(&data, 0, sizeof(t_data));
	data.analytics.time = &time;
	catch_signals();
	G_IS_RUNNING = 1;
	data.input = NULL;
	manage_inputs(argc, argv, &data);
	create_socket(&data);
	handle_icmp(&data);
	display_analytics(&data);
	clean(&data);
	return (EXIT_SUCCESS);
}
