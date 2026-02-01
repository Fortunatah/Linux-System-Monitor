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

void menu( sysInfo system ){
    printf("\n Linux System Monitor\n");
    printf("%s\n" , LINE);
    printf("CPU: %s\n" , system.cpuModel);
    printf("Cores: %d\n" , system.cpuCores);
    printf("CPU Usage: %.2f%c\n\n" ,  system.cpuPercentage , 37);
    printf("Memory: ");
    printf("\n\tTotal: %.2f GB\n" , system.memTotal);
    printf("\tUsed: %.2f GB\n" , system.memUsage);
    printf("\tFree: %.2f GB\n" , system.memFree);
    printf("\tUsage: %.2f%c \n\n" , system.memPercent , 37);
    printf("Uptime: %s\n" , system.upTime);
    printf("Processes:\n");
    printf("\tTotal: %d\n" , system.totalProcesses);
    printf("\tRunning: %d\n" , system.runningProcesses);
    printf("\n%s\n" , LINE);
}


int main(){
    sysInfo system = get_cpu_info();
    system.cpuPercentage = read_cpu_percentage();
    system = get_mem_info( system );
    system.upTime = get_uptime();
    system  = get_processes( system );
    while(1){
        clear_screen();
        menu( system );
        system.cpuPercentage = read_cpu_percentage();
        system.upTime = get_uptime();
        system  = get_processes( system );
        sleep(3);
    }
    return 0;
}
