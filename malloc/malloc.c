#include <stdio.h>
#include <stdlib.h>
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
 
int func() {
   struct perf_event_attr attr;
    memset(&attr, sizeof(struct perf_event_attr), 0); 
    int fd; 
    attr.type = PERF_TYPE_HARDWARE;
    
    fd = perf_event_open(&attr, 940, -1, -1, PERF_FLAG_FD_CLOEXEC);
    
    printf("hi\n");

    /*
	int i;
	char *addr;
	i = 0;
    char buffer[4096];
	unsigned long mask = 1 << 2;
	int pid = getpid();

    for (i = 0; i < 4096; i++) {
        buffer[i] = 'a' + i%23;
    }
    write(1, buffer, 4096);
	printf("pid: %d\n", getpid());
next:
	printf("%d\n", i);
	addr = malloc(4096*64);
	if (addr == NULL) {
		printf("Fail one time\n");
		goto next;
	}
	printf("%p\n", addr);
	for (int j = 0; j < 64; j++) {
		addr[j*4096] =12;
	}
	addr[0]=12;
    */
}

int func3() {
    func();
}

int func2() {
    func3();
}

int func1() {
    func2();
}

int funca() {
    func1();
}
int funcb() {
    func1();
}
int main()
{
    char *ptr = malloc(4*1024*1024);
    printf("ptr: %lx\n", ptr);
    int i = 0;
    /*
    for (i = 0; i < 1024; i++) {
        ptr[i*4096] = 1;
    }
    */

    return 0;
    funca();
    funcb();
    /*
	if (i++ < 1000) {
		sleep(2);
		goto next;
	}
    */

}
