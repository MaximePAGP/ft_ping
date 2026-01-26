#include "../inc/data.h"
#include <stdio.h>

void    display_target(t_data *data) {
    char ip_str[INET_ADDRSTRLEN];

    inet_ntop(AF_INET, &data->target_ip, ip_str, sizeof(ip_str));
    printf("PING %s (%s) 56(84) bytes of data.\n", data->input, ip_str);
}