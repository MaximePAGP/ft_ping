#include <stdio.h>

#include "../inc/data.h"

void	display_structure(t_data *data)
{
	printf("- target %s \n", data->hostname);
	printf("- ipv4 %d \n", data->ip);
	printf("- has flas %d \n", data->flags.has_packets_errors);
}