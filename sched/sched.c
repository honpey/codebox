#define  _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	int i;
	int pid;
	i = 0;
	unsigned long mask = 1 << 1;
	pid = getpid();
	sched_setaffinity(pid, sizeof(unsigned long), &mask);
	while(1);
	return 1;
}
