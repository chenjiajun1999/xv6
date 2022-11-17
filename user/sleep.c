//
// Created by chenjiajun1999 on 2022/11/17.
//
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int
main(int argc, char *argv[])
{
    int i;

    if(argc < 2){
        printf("Usage: sleep second...\n");
        exit(1);
    }

    for(i=1; i<argc; i++)
        sleep(atoi(argv[i]));

    exit(0);
}