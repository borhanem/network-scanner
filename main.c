#include <stdio.h>
#include "scanner.h"
#include "utils.h"

int main(int argc,char** argv){
    if(argc != 2){
        printf("Usage <host or subnet address>\n");
        exit(-1);
    }
    switch (addr_type(argv[1]))
    {
    case 0:
        printf("Invalid address\n");
        exit(-1);
    case 1:
        printf("host addr\n");
        break;
    case 2:
        printf("subnet addr\n");
        break;
    default:
        break;
    } 
}