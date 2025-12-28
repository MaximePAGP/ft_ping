#include "../inc/icmp.h"
#include <netinet/ip.h>
#include <string.h>
#include <stdio.h>

void	extract_icmp(struct iphdr *ip_hdr, t_icmp *icmp) {
	if (!ip_hdr) return;
	(void)icmp;
	 *icmp = *(t_icmp *)(ip_hdr + (ip_hdr->ihl * 4));
}
