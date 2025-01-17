#include "utils.h"

int addr_type(char **addr){
    if(check_addr_format(addr)){
        return 1;
    }else if(check_cidr_format(addr)){
        return 2;
    }else{
        return 0;
    }
}

int check_addr_format(char **addr)
{
    int values[4];
    if (sscanf(*addr, "%d.%d.%d.%d", &values[0], &values[1], &values[2], &values[3]) != 4)
    {
        return 0;
    }
    for (size_t i = 0; i < 4; i++)
    {
        if (values[i] < 0 || 255 < values[i])
        {
            return 0;
        }
    }
    return 1;
}

int check_cidr_format(char **addr)
{
    int values[4];
    int subnet;
    if (sscanf(*addr, "%d.%d.%d.%d/%d", &values[0], &values[1], &values[2], &values[3], &subnet) != 5)
    {
        return 0;
    }
    else if (subnet <= 0 || subnet <= 32)
    {
        return 0;
    }
    for (size_t i = 0; i < 4; i++)
    {
        if (values[i] < 0 || 255 < values[i])
        {
            return 0;
        }
    }
    return 1;
}
