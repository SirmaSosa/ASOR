#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>


int main (int argc, char**argv) {

  struct addrinfo h;
  struct addrinfo *result, *iterator;

  h.ai_family = AF_UNSPEC;
  h.ai_socktype = SOCK_DGRAM;
  h.ai_flags = AI_PASSIVE;

  getaddrinfo(argv[1], argv[2], &h, &result);

  int socke = socket(result->ai_family, result->ai_socktype, result->ai_protocol);


  bind(socke, result->ai_addr, result->ai_addrlen);   
  freeaddrinfo(result);
  
  char buf[2];
  char host[NI_MAXHOST];
  char serv[NI_MAXSERV];

  struct sockaddr_storage client_addr;
  socklen_t client_addrlen = sizeof(client_addr);
  int i = 0;
  int status;
  for (i = 0; i < 2; i++){
    pid_t pid;
    pid = fork();

    if (pid == 0) {
      while(1){
        ssize_t bytes = recvfrom(socket, buf, 2, 0, (struct sockaddr *) &client_addr, &client_addrlen);
        buf[1] = '\0';

        getnameinfo((struct sockaddr *) &client_addr, client_addrlen, host, NI_MAXHOST, serv, NI_MAXSERV, NI_NUMERICHOST|NI_NUMERICSERV);

        printf("%i byte(s) de %s:%s cuyo PID: %d\n", bytes, host, serv, getpid());

        time_t tiempo = time(NULL);
        struct tm *tm = localtime(&tiempo);
        size_t max;
        char s[20];

        if (buf[0] =='d'){
          size_t bytesT = strftime(s, max, "%Y-%m-%d", tm);
          s[bytesT] = '\0';

          sendto(socke, s, bytesT, 0, (struct sockaddr *) &client_addr, client_addrlen);
        }else if (buf[0] =='q'){
          printf("Saliendo...\n");
          exit(0);
        }else{
          printf("Error", buf[0]);
        }
      }
    }
  }
  return 0;
}
