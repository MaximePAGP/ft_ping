/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:32:49 by magrondi          #+#    #+#             */
/*   Updated: 2025/11/30 15:34:25 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "flags.h"

typedef struct s_data
{
	char	*hostname;
	int		ip;
	t_flags	flags;
}	t_data;

#endif