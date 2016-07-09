#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>

int main()
{
	int shmid;
	char *ptr, *shmptr;

	ptr = malloc(100000);
	if (ptr == NULL) {
		printf("fail \n");
		return -1;
	}
	printf("malloc:%p\n", (void *)ptr);

	shmid = shmget(IPC_PRIVATE, 100000, 0600);
	if (shmid < 0) {
		printf("fail \n");
		return -1;
	}

	shmptr = shmat(shmid, 0, 0);
	printf("shm:%p\n", (void *)shmptr);

}
