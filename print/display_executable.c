/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_executable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:30:22 by magrondi          #+#    #+#             */
/*   Updated: 2025/11/30 15:32:26 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

void	display_executable(void)
{
	char const	msg[] = "ping: missing host operand \nft_ping "
		"ft_ping "
		"\033[31m<IPv4> | <HOSTNAME>\033[0m "
		"\033[33m[OPTIONS]\033[0m\n"
		"\n"
		"\033[31m<IPv4> | <HOSTNAME>\033[0m   : Ip address or DNS (required)\n"
		"\033[33m[-v] | [-?]\033[0m           \
			: Display packets errors (optionnal)\n";

	write(STDERR_FILENO, &msg, strlen(msg));
}
