#include <stdlib.h>  
#include <stdio.h>  
#include <unistd.h>  
#include <string.h>  
#include <sys/ioctl.h>  
#include <linux/perf_event.h>  
#include <asm/unistd.h>  
#include <fcntl.h>
  
#define PID_NUM 7776
  
static long  
perf_event_open(struct perf_event_attr *hw_event, pid_t pid,
                int cpu, int group_fd, unsigned long flags)  
{  
    int ret;  
  
    ret = syscall(__NR_perf_event_open, hw_event, pid, cpu,
                   group_fd, flags);
    return ret;  
}  
  
int fdc[10];
int fdi[10];
int cpus = 2;
int setCycles(int cpus, int cgroupFd) {
    int i = 0;
    struct perf_event_attr pe;
    for (i = 0; i < cpus; i++) {
        memset(&pe, 0, sizeof(struct perf_event_attr));  
        pe.type = PERF_TYPE_HARDWARE;
        pe.size = sizeof(struct perf_event_attr);  
        //count cycles;  
        pe.config = PERF_COUNT_HW_CPU_CYCLES;  
        pe.disabled = 1;  
        pe.exclude_kernel = 1;  
        pe.exclude_hv = 1;  
        fdc[i] = perf_event_open(&pe, cgroupFd, i, -1, 0xc);  /* PERF_FLAG_PID_CGROUP */
        if (fdc[i] == -1) {  
            fprintf(stderr, "Error opening leader %llx\n", pe.config);  
            exit(EXIT_FAILURE);  
        }
        printf("fdc:%d\n", fdc[i]);
        ioctl(fdc[i], PERF_EVENT_IOC_RESET, 0);  
        ioctl(fdc[i], PERF_EVENT_IOC_ENABLE, 0);  
    }
}
int setInstructions(int cpus, int cgroupFd) {
    int i = 0;
    struct perf_event_attr pe;
    for (i = 0; i < cpus; i++) {
        memset(&pe, 0, sizeof(struct perf_event_attr));  
        pe.type = PERF_TYPE_HARDWARE;
        pe.size = sizeof(struct perf_event_attr);  
        //count cycles;  
        pe.config = PERF_COUNT_HW_INSTRUCTIONS;  
        pe.disabled = 1;  
        pe.exclude_kernel = 1;  
        pe.exclude_hv = 1;  
        fdi[i] = perf_event_open(&pe, cgroupFd, i, -1, 0xc); 
        if (fdi[i] == -1) {  
            fprintf(stderr, "Error opening leader %llx\n", pe.config);  
            exit(EXIT_FAILURE);  
        }
        printf("fdc:%d\n", fdi[i]);
        ioctl(fdi[i], PERF_EVENT_IOC_RESET, 0);  
        ioctl(fdi[i], PERF_EVENT_IOC_ENABLE, 0);  
    }
}

long long getInstructions() {
    int i = 0;
    long long inst = 0; 
    long long count = 0;
    for (i = 0; i < cpus; i++) {
        ioctl(fdi[i], PERF_EVENT_IOC_DISABLE, 0);
        read(fdi[i], &count, sizeof(long long));
        printf("fdi[%d]:%lld\n", i, count);
        inst += count;
    }
    return inst;
}
long long getCycles() {
    int i = 0;
    long long cycs = 0;
    long long count = 0;
    for (i = 0; i < cpus; i++) {
        ioctl(fdc[i], PERF_EVENT_IOC_DISABLE, 0);
        read(fdc[i], &count, sizeof(long long));
        printf("fdc[%d]:%lld\n", i, count);
        cycs += count;
    }
    return cycs;
}
  
int  
main(int argc, char **argv)
{  
    struct perf_event_attr pe;
    long long count,cycles,instructions;  
    double ipc;  
    int /*fdi, fdc, */fdFile;  
    int i;  

    fdFile = open("/sys/fs/cgroup/perf_event/loop", O_RDONLY);
    if (fdFile < 0) {
        printf("Fail to open cgroup path");
        return -1;
    }
  
    setInstructions(2, fdFile);
    setCycles(2, fdFile);

    sleep(5);

    instructions = getInstructions();
    cycles = getCycles();
  
    ipc=(double)instructions/(double)cycles;  
    printf("%lld instructions \n%lld cycles      ipc=%f\n", instructions,cycles,ipc);  
  
    for (i = 0; i < 2; i++) {
        close(fdi[i]);
        close(fdc[i]);  
    }
}  
