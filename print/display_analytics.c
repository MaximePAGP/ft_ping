
#include "../inc/data.h"
#include <stdio.h>

void	display_analytics(t_data *data)
{
	size_t	loses_packets = (data->analytics.received_packets - data->analytics.total_packets);
	double	percentage = 0.0;

	percentage = loses_packets / data->analytics.total_packets * 100;
	printf("--- %s ping statistics ---\n", data->input);
	printf("%ld packets transmitted, %ld received, %d%% packet loss, time 0ms\n",
		data->analytics.total_packets,
		data->analytics.received_packets,
		(int)percentage
	);
}