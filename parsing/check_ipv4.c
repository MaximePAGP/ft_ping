/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ipv4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:22:26 by magrondi          #+#    #+#             */
/*   Updated: 2025/12/07 00:35:26 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/data.h"

#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void	check_ipv4(t_data *data)
{
	if (inet_aton(data->input, &(data)->target_ip) == 0)
	{
		printf("invalide IPv4 address %d\n", (data)->target_ip.s_addr);
		exit(EXIT_FAILURE);
	}
}
