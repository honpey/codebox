#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <fcntl.h>

#define gettid() syscall(__NR_gettid)

pthread_t ntid;

void printids(const char *s)
{
	pid_t pid;
	pthread_t tid;

	pid = getpid();
    tid = gettid();
	tid = pthread_self();
	printf("%s pid %lu tid %lu (0x%lx) \n", s, (unsigned long)pid,
			(unsigned long)tid, (unsigned long)tid);
}

void *thr_fn(void *arg)
{
	printids("new thread:");
	while(1);
	return ((void *)0);
}

void *thr_fn1(void *arg)
{
	printf("thread1 returning:%d %ld\n", getpid(), gettid());
    char name[256];
    int count = 0;
    sprintf(name, "testFile%d", gettid());
    int fd = open(name, O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
    if (fd < 0) {
        printf("Fail to read the file\n");
    }
    char buffer[4096];
    printf("-------->----- %d %d\n", getpid(), gettid());
loop:
    lseek(fd, 0, SEEK_CUR);
    write(fd, buffer, 4096);
    fsync(fd);
    if (count++ == 50) {
        exit(0);
    }
    //printf("%d write: %d\n", gettid(), count++);
//    goto loop;

	return ((void *)1);
}
void *thr_fn2(void *arg)
{
	printf("thread2 returning\n");
    char name[256];
    int count = 0;
    sprintf(name, "testFile%d", gettid());
    int fd = open(name, O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
    if (fd < 0) {
        printf("Fail to read the file\n");
    }
    char buffer[4096];
loop:
    lseek(fd, 0, SEEK_CUR);
    write(fd, buffer, 4096);
    fsync(fd);
    //printf("%d write: %d\n", gettid(), count++);
    goto loop;

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
	err = pthread_create(&ntid2, NULL, thr_fn, NULL);
	if (err != 0) {
		printf("Something wrong 2\n");
		return 1;
	}

	err = pthread_create(&ntid3, NULL, thr_fn1, NULL);
	if (err != 0) {
		printf("Something wrong 1\n");
		return 1;
	}
	err = pthread_create(&ntid4, NULL, thr_fn, NULL);
	if (err != 0) {
		printf("Something wrong 2\n");
		return 1;
	}
	printf("hello world\n");
	printf("ntid1:%ld\n", ntid1);
	printf("ntid2:%ld\n", ntid2);

	err = pthread_join(ntid1, &ret1);
	err = pthread_join(ntid2, &ret2);
	err = pthread_join(ntid3, &ret3);
	err = pthread_join(ntid4, &ret4);

	printf("ret1:0x%lx\n", (unsigned long)ret1);
	printf("ret1:0x%lx\n", (unsigned long)ret2);
	printf("ret2:0x%lx\n", (unsigned long)ret3);
	printf("ret2:0x%lx\n", (unsigned long)ret4);
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
