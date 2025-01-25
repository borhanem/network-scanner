#include "utils.h"

int addr_type(const char *addr)
{
    if (check_addr_format(addr))
    {
        return 1;
    }
    else if (check_cidr_format(addr))
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int check_addr_format(const char *ip)
{
    int num, dots = 0;
    char *endptr;

    if (ip == NULL || strlen(ip) == 0)
        return 0;

    char *ipCopy = strdup(ip);
    char *ptr = strtok(ipCopy, ".");
    while (ptr)
    {
        if (!isdigit(*ptr) || (num = strtol(ptr, &endptr, 10), *endptr != '\0'))
        {
            free(ipCopy);
            return 0;
        }
        if (num < 0 || num > 255)
        {
            free(ipCopy);
            return 0;
        }
        ptr = strtok(NULL, ".");
        dots++;
    }
    free(ipCopy);
    return dots == 4;
}

int check_cidr_format(const char *addr)
{
    char ip[IP_ADDR_LENGTH];
    int prefix;
    char buffer[1024];

    if (sscanf(addr, "%15[^/]/%d%s", ip, &prefix, buffer) != 2)
    {
        return 0;
    }

    if (prefix < 0 || prefix > 32)
    {
        return 0;
    }

    int octets[4];
    if (sscanf(ip, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]) != 4)
    {
        return 0;
    }

    for (int i = 0; i < 4; i++)
    {
        if (octets[i] < 0 || octets[i] > 255)
        {
            return 0;
        }
    }

    return 1;
}
