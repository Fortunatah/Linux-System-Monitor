#ifndef GET_SYSTEM_INFO_H
#define GET_SYSTEM_INFO_H

void clear_screen();

typedef struct{
    char *cpuModel;
    int cpuCores;
    double cpuPercentage;
    double memTotal;
    double memFree;
    double memUsage;
    double memPercent;
    char *upTime;
    int totalProcesses;
    int runningProcesses;
}sysInfo;

sysInfo get_cpu_info();
sysInfo get_mem_info( sysInfo system );
char *get_uptime();
double read_cpu_percentage();
sysInfo get_processes( sysInfo system )

#endif