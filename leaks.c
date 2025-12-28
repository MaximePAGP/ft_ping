#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(void) {
    struct addrinfo hints;
    struct addrinfo *res;
    struct sockaddr_in *addr_in;
    int ret;

    res = NULL;
    addr_in = NULL;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    ret = getaddrinfo("172.217.20.46", NULL, &hints, &res);
    if (ret != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
        return 1;
    }
    addr_in = (struct sockaddr_in *)res->ai_addr;
    printf("IP Address: %s\n", inet_ntoa(addr_in->sin_addr));
    freeaddrinfo(res);
    return 0;
}