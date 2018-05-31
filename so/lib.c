#include <linux/perf_event.h>
#include <linux/hw_breakpoint.h>
#include <sched.h>
#include <asm/unistd.h>

static long  
perf_event_open(struct perf_event_attr *hw_event, pid_t pid,  
                int cpu, int group_fd, unsigned long flags)  
{  
    int ret;  
  
    ret = syscall(__NR_perf_event_open, hw_event, pid, cpu,  
                   group_fd, flags);  
    return ret;  
}  


int add(int a, int b)
{
	struct perf_event_attr attr;
    memset(&attr, sizeof(struct perf_event_attr), 0); 
    int fd; 
    attr.type = PERF_TYPE_HARDWARE;
    
    fd = perf_event_open(&attr, 940, -1, -1, PERF_FLAG_FD_CLOEXEC);
    return a+b;
}

int minus(int a, int b)
{
	struct perf_event_attr attr;
    memset(&attr, sizeof(struct perf_event_attr), 0); 
    int fd; 
    attr.type = PERF_TYPE_HARDWARE;
    
    fd = perf_event_open(&attr, 940, -1, -1, PERF_FLAG_FD_CLOEXEC);
    return a-b;
}
