#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t ntid;

void printids(const char *s)
{
	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();
	printf("%s pid %lu tid %lu (0x%lx) \n", s, (unsigned long)pid,
			(unsigned long)tid, (unsigned long)tid);
}

void *thr_fn(void *arg)
{
	printids("new thread: ");
	int i = 70;
	char *addr;
	for (; i >= 0; i--) {
		addr = malloc(4096);
		addr[0] = 0;
	}
	while(1);
	return ((void *)0);
}

void *thr_fn1(void *arg)
{
	printf("thread1 returning\n");
	int i = 70;
	char *addr;
	for (; i >= 0; i--) {
		addr = malloc(4096);
		addr[0] = 0;
	}
	while(1);
	return ((void *)1);
}
void *thr_fn2(void *arg)
{
	printf("thread2 returning\n");
	int i = 70;
	char *addr;
	for (; i >= 0; i--) {
		addr = malloc(4096);
		addr[0] = 0;
	}
	while(1);
	return ((void *)2);
}
int main()
{
	int err;
	pthread_t ntid1, ntid2;
	pthread_t ntid3, ntid4;
	void *ret1, *ret2;
	void *ret3, *ret4;

	printf("pid: %d\n", getpid());
	err = pthread_create(&ntid1, NULL, thr_fn1, NULL);
	if (err != 0) {
		printf("Something wrong 1\n");
		return 1;
	}
	err = pthread_create(&ntid2, NULL, thr_fn2, NULL);
	if (err != 0) {
		printf("Something wrong 2\n");
		return 1;
	}

	err = pthread_create(&ntid3, NULL, thr_fn1, NULL);
	if (err != 0) {
		printf("Something wrong 1\n");
		return 1;
	}
	err = pthread_create(&ntid4, NULL, thr_fn2, NULL);
	if (err != 0) {
		printf("Something wrong 2\n");
		return 1;
	}
	printf("hello world\n");
	printf("ntid1:%d\n", ntid1);
	printf("ntid2:%d\n", ntid2);

	err = pthread_join(ntid1, &ret1);
	err = pthread_join(ntid2, &ret2);
	err = pthread_join(ntid3, &ret3);
	err = pthread_join(ntid4, &ret4);

	printf("ret1:0x%lx\n", ret1);
	printf("ret1:0x%lx\n", ret2);
	printf("ret2:0x%lx\n", ret3);
	printf("ret2:0x%lx\n", ret4);
	while(1);

	return 1;


	
	err = pthread_create(&ntid, NULL, thr_fn, NULL);
	if (err != 0) {
		printf("Cant't create thread\n");
		return -1;
	}
	printids("main thread: ");
	sleep(1);
	while(1);
	exit(0);
}
