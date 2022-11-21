#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int main(){
 
	mode_t prev = umask(027);

	int fd = open("./ej6.txt", O_CREAT, 0777);

	mode_t last = umask(prev);

	return 0;
}
