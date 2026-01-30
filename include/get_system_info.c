/*
This is where we will get the system info for the raspberry
pi*/

// Librares
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_system_info.h"


void clear_screen(){
    system("clear");
} //void clear_screen()

char *get_cpu_info(){
    FILE *file = fopen("/proc/cpuinfo" , "r");
    char buffer[256];
    char *line = malloc(sizeof(buffer));
    while(fgets(buffer, sizeof(buffer) , file)){
        if(strstr(buffer , "Model")){
            printf("buffer = %s\n" , buffer);
        }
    }

    memcpy( line , buffer , sizeof(buffer));
    fclose(file);
    return line;
}