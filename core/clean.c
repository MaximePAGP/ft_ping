/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 21:36:07 by magrondi          #+#    #+#             */
/*   Updated: 2025/12/24 12:24:15 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/data.h"
#include <stdlib.h>

void	clean(t_data *data)
{
	if (data->dns_infos)
		freeaddrinfo(data->dns_infos);
	if (data->input)
		free(data->input);
	close(data->socket_fd);
}
