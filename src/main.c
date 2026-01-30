/*
This is the main file for the menu
All statements will run through this
*/

// libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> // linux module used for time
#include "../include/get_system_info.h"


#define LINE "==============================\n"

void menu( cpuInfo cpu ){
    printf("\n Linux System Monitor\n");
    printf("%s\n" , LINE);
    printf("CPU: %s\n" , cpu.model);
    printf("Cores: 8\n");
    printf("CPU Usage: 12.4\n\n");
    printf("Memory: ");
    printf("\n\tTotal: 15.6 GB\n");
    printf("\tUsed: 6.2 GB\n");
    printf("\tFree: 9.4 GB\n");
    printf("\tUsage: 39.7 \n\n");
    printf("Uptime: 03:42:18\n");
    printf("Processes:\n");
    printf("\tTotal: 312\n");
    printf("\tRunning: 4");
    printf("\n%s\n" , LINE);
}


int main(){
    cpuInfo cpu = get_cpu_info();
    while(1){
        clear_screen();
        menu( cpu );
        sleep(3);
    }
    return 0;
}
