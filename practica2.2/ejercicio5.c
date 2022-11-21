#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int main(){
	int fd =open("./eje5.txt",O_CREAT,0645);
	return 1;
}
