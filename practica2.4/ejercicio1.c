#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int argv, char** argc){
	pid_t pid;
  	if (argv < 2) {
    	printf("Error: Introduce los comandos\n");
  	}

  	int fd[2];
	int pipe(int fd[2]);
	pid = fork();
	if(pid  == -1)
		 perror("Error");

	else if(pid == 0){
		dup2(fd[0],0);
                close(fd[1]);
                close(fd[0]);
		execlp(argc[1],argc[1],argc[2],(char *)0);
	}else{
		dup2(fd[1],1);
		close(fd[1]);
		close(fd[0]);
		execlp(argc[3],argc[3],argc[4],(char *)0);
	}
}
