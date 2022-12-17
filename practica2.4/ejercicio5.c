#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(){

	char buffer[257];
	char *tub1 = "tub1";
	char *tub2 = "tub2";

	mkfifo(tub1, 0644);
 	mkfifo(tub2, 0644);

  int pipe1 = open(tub1, O_RDONLY | O_NONBLOCK);
  int pipe2 = open(tub2, O_RDONLY | O_NONBLOCK);

  int x, pipActual;

  while (x != -1 ) {
    fd_set group;
    FD_ZERO(&group);
    FD_SET(pipe1, &group);
    FD_SET(pipe2, &group);
    int pipActual;

	x = select((pipe1 < pipe2) ? pipe2 + 1 : pipe1 + 1, &group, NULL,NULL,NULL);
	
	if (x > 0){
     	 if (FD_ISSET(pipe1, &group)) {
       		 pipActual = 1;
       		 pipActual = pipe1;
      } else if (FD_ISSET(pipe2, &group)) {
		pipActual = 2;
		pipActual = pipe2;
      	}

      	ssize_t tam = 256;
	while (tam == 256) {
		tam = read(pipActual, buffer, 256);
		buffer[tam] = '\0';
		printf("Tub %i: %s", pipActual, buffer);
			}


      	if (tam != 256 && pipActual == 1) {
        	close(pipe1);
        	pipe1 = open(tub1, O_RDONLY | O_NONBLOCK);
		
      } else if(tam != 256 && pipActual == 2) {
       		 close(pipe2);
        	pipe2 = open(tub2, O_RDONLY | O_NONBLOCK);
		  }
    }

  }


  close(pipe1);
  close(pipe2);
  return 0;
}
