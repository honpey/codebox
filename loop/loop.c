#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <pthread.h>

int globalA = 0;
int globalB = 0;
int funcc() {
    globalA++;
}

int funcd() {
    globalA--;
}

int buffer[409600000];

int funcb() {
	globalB++;
//	sleep(3);
//	printf("hello %d\n", globalB);
    int i = 0;
    while(i++ < 100000000) {
        /*
        if (i%1) {
            funcc();
        } else {
            funcd();
        }
        */
    };
    /*
    for (i = 0; i < 100000; i++) {                     
        int value =  (4906*13*17*i/394343)*2332;
        buffer[i*4096] = value;
        buffer[i*4096+2048] = value*233242342;
    }
    */
}
int funca() {
	globalA++;
	funcb();
}
typedef int *pointerInt;

void *fn(void *arg) {
    int i = 0;
    int count = 0;
again:
    while(i++ < 100000000) {
    }
    if (count++ < 5)
        goto again;
}
int main()
{
	int i = 12;
	pointerInt pInt;
	pInt = &i;
	printf("pInt:%p(%d)\n", pInt, *pInt);
    cpu_set_t set;
    CPU_ZERO(&set);
   // CPU_SET(1, &set);
    CPU_SET(0, &set);
    int ret = sched_setaffinity(getpid(), sizeof(set), &set);
    printf("ret: %d", ret);
    i = 0;
    /*
    pthread_t ntid1, ntid2;
    pthread_t ntid3, ntid4;
    void *ret1;
    int err;
    err = pthread_create(&ntid1, NULL, fn, NULL);
    err = pthread_create(&ntid2, NULL, fn, NULL);
    err = pthread_join(ntid1, &ret1);
    err = pthread_join(ntid2, &ret1);
    */
	while(i++ < 5) {
//		sleep(10);
	funca();
	}
	return 0;
}
