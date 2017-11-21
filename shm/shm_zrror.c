#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define MEMSIZE 512*1024*1023

int
main()
{
    int shmid;
    char *ptr;
    pid_t pid;
    struct shmid_ds buf;
    int ret;

    shmid = shmget(IPC_PRIVATE, MEMSIZE, 0600);
    if (shmid<0) {
        perror("shmget()");
        exit(1);
    }

    ret = shmctl(shmid, IPC_STAT, &buf);
    if (ret < 0) {
        perror("shmctl()");
        exit(1);
    }

    printf("shmid: %d\n", shmid);
    printf("shmsize: %d\n", buf.shm_segsz);

    buf.shm_segsz *= 2;

    ret = shmctl(shmid, IPC_SET, &buf);
    if (ret < 0) {
        perror("shmctl()");
        exit(1);
    }

    ret = shmctl(shmid, IPC_SET, &buf);
    if (ret < 0) {
        perror("shmctl()");
        exit(1);
    }

    printf("shmid: %d\n", shmid);
    printf("shmsize: %d\n", buf.shm_segsz);


    pid = fork();
    if (pid<0) {
        perror("fork()");
        exit(1);
    }
    if (pid==0) {
        ptr = shmat(shmid, NULL, 0);
        if (ptr==(void*)-1) {
            perror("shmat()");
            exit(1);
        }
        bzero(ptr, MEMSIZE);
        strcpy(ptr, "Hello!");
        exit(0);
    } else {
        wait(NULL);
        ptr = shmat(shmid, NULL, 0);
        if (ptr==(void*)-1) {
            perror("shmat()");
            exit(1);
        }
        puts(ptr);
        exit(0);
    }
}
