#ifndef CPU_INFO_LIB
#define CPU_INFO_LIB

typedef struct {
    
    char *manufacturer;
    float clockSpeed;
    int userTime;
    int niceTime;
    int systemTime;
    int idleTime;
    int iowaitTime;
    int irqTime;

} CpuInfo;

CpuInfo *getCpuInfo();
CpuInfo *getCpuTime();
CpuInfo *getCpuInfoAndTime();

#endif