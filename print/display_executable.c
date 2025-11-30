/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_executable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:30:22 by magrondi          #+#    #+#             */
/*   Updated: 2025/11/30 15:55:23 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

void	display_executable(void)
{
	char const	msg[] = "ft_ping: missing host operand \n"
		"Try 'ping --help' or 'ping --usage' for more information.\n";

	write(STDERR_FILENO, &msg, strlen(msg));
}
