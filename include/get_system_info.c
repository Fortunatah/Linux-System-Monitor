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

char *get_substring( char *source , char *destination , int start_index , int length){
    strncpy( destination , source + start_index , length );
    destination[length] = '\\0';
}

cpuInfo get_cpu_info(){
    cpuInfo tempCPU;
    FILE *file = fopen("/proc/cpuinfo" , "r");
    char buffer[256];
    while(fgets(buffer, sizeof(buffer) , file)){
        if(strstr(buffer , "Model")){
            char *modelSub = (char *)malloc(sizeof(buffer));
            int modelLength = (int) strlen(buffer);
            tempCPU.model = get_substring( buffer , modelSub , strchr(buffer , ":") , modelLength);
        }
    }

    fclose(file);
}