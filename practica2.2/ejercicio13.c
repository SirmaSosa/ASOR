#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv){

        int fd = open(argv[1], O_CREAT | O_RDWR);
        int fd2 = dup2(fd,2);
	int fd3 = dup2(fd,1);
        printf("Se ha redirigido a %d", argv[1]);
        return 1;
}
