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
    destination[length] = '\0';
    return destination;
}

char *read_stat_file(){
    FILE *file = fopen("/proc/stat" , "r");
    char buffer[256];
    char *line = malloc(sizeof(buffer));
    while(fgets(buffer, sizeof(buffer) , file)){
        if(strstr( buffer , "cpu")){
            int length = (int) strlen(buffer);
            strcpy( line  , buffer );
            line[length] = '\0';
            return line;
        }
    }
}


int read_cpu_percentage(){
    char *firstPass = read_stat_file();
    printf("first pass = %s\n", firstPass);
    int percentage = 0;
    return percentage;
}

cpuInfo get_cpu_info(){
    cpuInfo tempCPU;
    FILE *file = fopen("/proc/cpuinfo" , "r");
    char buffer[256];
    int coresAmount = 0;
    while(fgets(buffer, sizeof(buffer) , file)){
        // get the model of the processor
        if(strstr(buffer , "Model")){
            char *destination = (char *)malloc(sizeof(buffer));
            int length = (int) strlen(buffer);
            char *pos = strchr(buffer , ':');
            int index = pos - buffer + 2;
            tempCPU.model= get_substring( buffer , destination , index , length);
        }
        // see how many cores there are
        if(strstr(buffer , "processor")){
            coresAmount++;
        }
        
    }
    // if cores ammount is greater than zero
    if( coresAmount > 0 ){
        tempCPU.cores = coresAmount;
    }

    fclose(file);
    return tempCPU;
}