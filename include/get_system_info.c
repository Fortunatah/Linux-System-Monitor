/*
This is where we will get the system info for the raspberry
pi*/

// Librares
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // linus time library
#include <ctype.h>
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
    return NULL;
}

int get_idle( char *pass){
    int i = 0;
    int spaceCount = 0; // use space to determine where idle is in the string
    int count = 0;
    int total = 0;
    char add[32];   // enough for CPU numbers
    while (pass[i] != '\0') { // go until end of the line
        // if we have a space add to it
        if (pass[i] == ' ') {
            spaceCount++;
            // if we have 4 or 5 spaces we need to add
            if(spaceCount == 4 || spaceCount == 5){
                add[count] = '\0';
                total += strtol( add , NULL , 10);
                count = 0;
            }
        }
        // if we have 3 or 4 spaces, we need to start making our string
        if(spaceCount == 3 || spaceCount == 4){
            add[count++] = pass[i];
        }
        i++;
    }
    return total;
}
int get_line_total(char *pass) {
    int i = 0;
    int count = 0;
    int total = 0;
    char add[32];   // enough for CPU numbers

    while (pass[i] != '\0') { // go until end of the line
        if (pass[i] == ' ') {
            if (count > 0) {
                // add current num to total
                add[count] = '\0';
                total += strtol(add, NULL, 10);
                count = 0;
            }
        } else {
            add[count++] = pass[i];
        }
        i++;
    }

    // last number
    if (count > 0) {
        add[count] = '\0';
        total += strtol(add, NULL, 10);
    }

    return total;
}
double read_cpu_percentage(){
    // get the strings from /proc/stat
    char *firstPass = read_stat_file();
    sleep(1);
    char *secondPass = read_stat_file();
    // get the length of strings
    int firstLength = (int) strlen(firstPass);
    int secondLength = (int) strlen(secondPass);
    // get rid of the "cpu   " from the string
    char *readOne = (char *)malloc(256);
    get_substring( firstPass , readOne , 5 , firstLength);
    char *readTwo = (char *)malloc(256);
    get_substring( secondPass , readTwo , 5 , secondLength);
    // find the total from each
    int firstTotal = get_line_total( readOne );
    int secondTotal = get_line_total( readTwo );
    // get the idle time from each
    int idleOne = get_idle( readOne );
    int idleTwo = get_idle( readTwo );
    // do our calculations
    double totalDiff = (double) secondTotal - firstTotal;
    double idleDiff = (double) idleTwo - idleOne;
    double percentage = ((totalDiff - idleDiff) / totalDiff) * 100.0;
    return percentage;
}

sysInfo get_cpu_info(){
    sysInfo tempCPU;
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
            tempCPU.cpuModel= get_substring( buffer , destination , index , length);
        }
        // see how many cores there are
        if(strstr(buffer , "processor")){
            coresAmount++;
        }
        
    }
    // if cores ammount is greater than zero
    if( coresAmount > 0 ){
        tempCPU.cpuCores = coresAmount;
    }

    fclose(file);
    return tempCPU;
}

typedef struct{
    int start;
    int end;
}index;

index get_index( char *line){
    index Index
    Index.start = 0; // we will zero on both of them as a check
    // grab the start
    for(int i = 0; line[i] != '\0'; i++){
        // find the first digit
        if(isdigit(line[i])){
            Index.start = i;
            break;
        }
    }
    // start  from the first digit
    for( i = Index.start; line[i] != '\0' ; i++){
        if(line[i] == ' '){
            Index.end = i;
            break;
        }
    }
    return Index;
}

sysInfo get_mem_info( sysInfo system ){
    FILE *file = fopen("/proc/meminfo" , "r");
    char buffer[256];
    while(fgets(buffer, sizeof(buffer) , file)){
        // get the model of the processor
        if(strstr(buffer , "MemTotal")){
            char *destination = (char *)malloc(sizeof(buffer));
            index Index = get_index();
            printf("start = %d ,  end = %d\n" , Index.start , Index.end; );

        }
        
    }
}