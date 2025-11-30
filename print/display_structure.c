/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_structure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:32:34 by magrondi          #+#    #+#             */
/*   Updated: 2025/11/30 15:32:44 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../inc/data.h"

void	display_structure(t_data *data)
{
	printf("- target %s \n", data->hostname);
	printf("- ipv4 %d \n", data->ip);
	printf("- has flas %d \n", data->flags.has_packets_errors);
}
