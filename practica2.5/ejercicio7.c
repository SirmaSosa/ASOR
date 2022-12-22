#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char**argv){

  struct addrinfo info;
  struct addrinfo *result;
  info.ai_family = AF_UNSPEC;
  info.ai_socktype = SOCK_STREAM;
  info.ai_flags = AI_PASSIVE;
  char host[NI_MAXHOST];
  char server[NI_MAXSERV]; 

  int socket = socket(result->ai_family, result->ai_socktype, 0);
  connect(socket,(struct sockaddr *)result->ai_addr, result->ai_addrlen);
  freeaddrinfo(result);
  char buffin[256];
  char buffout[256];
  ssize_t x;


  while (1) {
    x = read(0,buffout, 255);
    buffout[x] = '\0';
    send(socketTCP,buffout, x, 0);


    if ((buffout[1] == 'q') && (x == 2)) {
      printf("Conexión finalizada\n");
      break;
    }

    x = recv(socket, buffin, 255, 0);
    buffin[x] = '\0';
    printf("OUT:%s\n", buffin);
  }

  close(socketTCP);
  return 0;
}
