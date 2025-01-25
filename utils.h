#ifndef UTILS_H_
#define UTILS_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define IP_ADDR_LENGTH 16
#define MAX_STR_BUFF 1024

int addr_type(const char *addr);

int check_addr_format(const char *ip);

int check_cidr_format(const char *addr);

#endif // UTILS_H_