#include <stdlib.h>  
#include <stdio.h>  
#include <unistd.h>  
#include <string.h>  
#include <sys/ioctl.h>  
#include <linux/perf_event.h>  
#include <asm/unistd.h>  
  
#define PID_NUM 17828
  
static long  
perf_event_open(struct perf_event_attr *hw_event, pid_t pid,  
                int cpu, int group_fd, unsigned long flags)  
{  
    int ret;  
  
    ret = syscall(__NR_perf_event_open, hw_event, pid, cpu,  
                   group_fd, flags);  
    return ret;  
}  
  
  
int  
main(int argc, char **argv)  
{  
    struct perf_event_attr pe;
    long long count,cycles,instructions;  
    double ipc;  
    int fd;  
    int i;  
    int filefd = -1;
  
    memset(&pe, 0, sizeof(struct perf_event_attr));  
    pe.type = PERF_TYPE_HARDWARE;  
    pe.size = sizeof(struct perf_event_attr);  
    pe.config = PERF_COUNT_HW_INSTRUCTIONS;  
    //pe.config = PERF_COUNT_HW_CPU_CYCLES;  
    pe.disabled = 1;  
    pe.exclude_kernel = 1;  
    pe.exclude_hv = 1;  

    int filefd = open("/sys/fs/cgroup/perf_event/loop", O_RDWR, 0);
    if (filefd < 0) {
        printf("Fail to read /sys/fs/cgroup/perf_event/loop\n");
        return -1;
    }

  
    //count cycles;  
    fd = perf_event_open(&pe, 7776, -1, -1, 0); 
    if (fd == -1) {  
       fprintf(stderr, "Error opening leader %llx\n", pe.config);  
       exit(EXIT_FAILURE);  
    }  
    printf("fd:%d\n", fd);
    ioctl(fd, PERF_EVENT_IOC_RESET, 0);  
    ioctl(fd, PERF_EVENT_IOC_ENABLE, 0);  
    sleep(5);
    ioctl(fd, PERF_EVENT_IOC_DISABLE, 0);
    read(fd, &count, sizeof(long long));
    cycles=count;
  
    //count instructions
    pe.config = PERF_COUNT_HW_INSTRUCTIONS;
    fd = perf_event_open(&pe, 7776, -1, -1, 0);
    if (fd == -1) {  
       fprintf(stderr, "Error opening leader %llx\n", pe.config);  
       exit(EXIT_FAILURE);  
    }  
    ioctl(fd, PERF_EVENT_IOC_RESET, 0);  
    ioctl(fd, PERF_EVENT_IOC_ENABLE, 0);  
    sleep(5);
    ioctl(fd, PERF_EVENT_IOC_DISABLE, 0);  
    read(fd, &count, sizeof(long long));  
    instructions=count;  
  
    ipc=(double)instructions/(double)cycles;  
    printf("Used %lld instructions\n %lld cycles      ipc=%f\n", instructions,cycles,ipc);  
  
    close(fd);  
}  
