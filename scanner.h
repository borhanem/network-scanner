#ifndef SCANNER_H_
#define SCANNER_H_

#include <sys/socket.h>
#include <linux/if_packet.h>
#include <net/ethernet.h>
#include <netinet/ether.h>
#include <netinet/in.h>
#include <stdlib.h>

void subnet_scan(char** subnet_addr);

void host_scan(char** host_addr);


#endif //SCANNER_H_
