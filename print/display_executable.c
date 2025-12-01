/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_executable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:30:22 by magrondi          #+#    #+#             */
/*   Updated: 2025/12/01 11:08:53 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

void	display_executable(void)
{
	char const	msg[] = "ping: usage error: Destination address required\n";

	write(STDERR_FILENO, &msg, strlen(msg));
}
