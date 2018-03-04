#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
	int rc,old_scheduler_policy;
	struct sched_param my_params;

	my_params.sched_priority=sched_get_priority_max(SCHED_FIFO);// 尽可能高的实时优先级
	rc=sched_setscheduler(0,SCHED_FIFO,&my_params);
	if(rc<0)
	{
		perror("sched_setscheduler to SCHED_FIFO error");
		exit(0);
	}
	old_scheduler_policy=sched_getscheduler(0);

	printf("the current scheduler = %d \n",old_scheduler_policy);

	int pid = getpid();
	unsigned long mask = 1 << 1;
	sched_setaffinity(pid, sizeof(unsigned long), &mask);
	while(1);
	return 0;
} 
