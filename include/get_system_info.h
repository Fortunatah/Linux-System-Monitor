#ifndef GET_SYSTEM_INFO_H
#define GET_SYSTEM_INFO_H

void clear_screen();

typedef struct{
    char *model;
    int cores;
}cpuInfo;

cpuInfo get_cpu_info();

#endif