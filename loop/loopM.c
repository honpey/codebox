#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

int globalA = 0;
int globalB = 0;

int funcb() {
	globalB++;
//	sleep(3);
//	printf("hello %d\n", globalB);
}
int funca() {
	globalA++;
	funcb();
}
typedef int *pointerInt;

int main()
{
    /*
	int i = 12;
	pointerInt pInt;
	pInt = &i;
	printf("pInt:%p(%d)\n", pInt, *pInt);
    cpu_set_t set;
    CPU_ZERO(&set);
    CPU_SET(0, &set);
    int ret = sched_setaffinity(getpid(), sizeof(set), &set);
    printf("ret: %d", ret);
    */
    int i = 0;
	while(1) {
        i = 0;
        while (i++ < 0xfffffff);
        sleep(1);
//		sleep(10);
	funca();
	}
	return 0;
}
