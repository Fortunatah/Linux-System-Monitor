#ifndef GET_SYSTEM_INFO_H
#define GET_SYSTEM_INFO_H

void clear_screen();

typedef struct{
    char *cpuModel;
    int cpuCores;
    double cpuPercentage;
    double memTotal;
    double memFree;
}sysInfo;

sysInfo get_cpu_info();
sysInfo get_mem_info( sysInfo system );
double read_cpu_percentage();

#endif