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
            char *destination = (char *)malloc(sizeof(buffer));
            int length = (int) strlen(buffer);
            char *pos = strchr(buffer , ":");
            int index = pos - buffer;
            tempCPU.model = get_substring( buffer , destination , index , length);
        }
    }

    fclose(file);
}