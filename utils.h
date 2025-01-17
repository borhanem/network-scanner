#ifndef UTILS_H_
#define UTILS_H_

#include <stdio.h>
#include <string.h>

int addr_type(char **addr);

int check_addr_format(char **addr);

int check_cidr_format(char **addr);

#endif //UTILS_H_