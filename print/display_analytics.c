
#include "../inc/data.h"
#include <stdio.h>
#include <stdlib.h>

void	display_analytics(t_data *data)
{
	int	loses_packets = abs((int) data->analytics.received_packets - (int) data->analytics.total_packets);
	double	percentage	;

	percentage = (double) (loses_packets / (int) data->analytics.total_packets);
	printf("qweqweqw %d %d %d \n", loses_packets,  (int) data->analytics.received_packets ,(int) data->analytics.total_packets);

	printf("coucou %f \n", percentage);
	printf("--- %s ping statistics ---\n", data->input);
	printf("%ld packets transmitted, %ld received, %f%% packet loss, time 0ms\n",
		data->analytics.total_packets,
		data->analytics.received_packets,
		percentage
	);
}