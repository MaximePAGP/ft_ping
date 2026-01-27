
#include "../inc/data.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


void display_analytics(t_data *data)
{
    long            sent = data->analytics.total_packets;
    long            received = data->analytics.received_packets;
    long            lost = sent - received;
    double          loss_percentage = 0.0;
    struct  timeval end;


    if (sent > 0)
        loss_percentage = ((double)lost / (double)sent) * 100.0;

    gettimeofday(&end, NULL);
    long elapsed_ms = (end.tv_sec - data->analytics.time->tv_sec) * 1000
                    + (end.tv_usec - data->analytics.time->tv_usec) / 1000;

    printf("\n--- %s ping statistics ---\n", data->input);
    printf("%ld packets transmitted, %ld received, %.2f%% packet loss, time %ldms\n",
           sent,
           received,
           loss_percentage,
           elapsed_ms);
}
