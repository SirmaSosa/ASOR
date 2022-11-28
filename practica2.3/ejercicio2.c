#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
int main(int argc,char **argv){
	int pid = atoi(argv[1]);
	int process = sched_getscheduler(pid);

	if(process == SCHED_OTHER)
		printf("Other\n");
	else if(process == SCHED_FIFO)
		printf("FIFO\n");
	else if( process == SCHED_RR)
		printf("RR\n");
	
	struct sched_param p;
	sched_getparam(pid,&p);
	printf("El proceso con id %i tiene una prioridad %i\n",pid,p.sched_priority);
	
	int max = sched_get_priority_max(process);
	int min = sched_get_priority_min(process);
	printf("Max:%i,Min:%i\n",max,min);
}
