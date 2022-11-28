#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>

int main(){
 	printf("PID: %i\n", getpid());
	printf("PPID: %i\n", getppid());
	printf("SID: %i\n", getsid(getpid()));
	printf("PGID: %i\n", getpgid(getpid()));

	struct rlimit lim;
	getrlimit(RLIMIT_NOFILE, &lim);
	printf("LIMIT: %li\n", lim.rlim_max);
}
