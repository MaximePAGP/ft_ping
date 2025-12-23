/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 21:36:07 by magrondi          #+#    #+#             */
/*   Updated: 2025/12/23 21:44:08 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/data.h"
#include <stdlib.h>

void	clean(t_data *data)
{
	if (data->input) {
		free(data->input);
    }
	free(data->dns_infos->ai_addr);
	free(data->dns_infos);
	close(data->socket_fd);
}