#include <stdio.h>
#include <stdlib.h>

int main(){
 	printf("PID: %i\n", getpid());
	printf("PPID: %i\n", getppid());
	printf("SID: %i\n", getsid(getpid()));
	printf("PGID: %i\n", getpgid(getpid()));

	struct rlimit lim;
	getrlimit(RLIMIT_NOFILE, &lim);
	printf("LIMIT: %i\n" lim.rlimit_max);
}
