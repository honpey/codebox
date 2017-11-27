#include <stdio.h>
#include <stdlib.h>
#include <linux/perf_event.h>
#include <linux/hw_breakpoint.h>

int main() {
	struct perf_event_attr attr;
	memset(&attr, sizeof(struct perf_event_attr), 0);
	int fd;
	attr.type = PERF_TYPE_HARDWARE;
			
	fd = perf_event_open(&attr, 940, -1, -1, PERF_FLAG_FD_CLOEXEC);
		

	printf("hello world\n");
	return 0;
}
