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
    char *lines;
    lines = system("cat /proc/cpuinfo");
    printf("string = %s\n" , lines);
    return lines;
}