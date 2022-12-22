#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char**argv) {
  struct addrinfo info;
  struct addrinfo *result, *it;
  char hbuf[NI_MAXHOST],sbuf[NI_MAXHOST];
  struct sockaddr *addr;     /* input */
  socklen_t addrlen;
  info.ai_family = AF_UNSPEC;    /* Allow IPv4 or IPv6 */
  info.ai_socktype = 0; /* Datagram socket */
  info.ai_flags = AI_PASSIVE;    /* For wildcard IP address */
  info.ai_protocol = 0;          /* Any protocol */
  info.ai_canonname = NULL;
  info.ai_addr = NULL;
  info.ai_next = NULL;

	getaddrinfo(argv[1], NULL, &info, &result); 


  for (it = result; it != NULL; it = it->ai_next) {
    switch (it->ai_family) {
      case AF_INET:;
        struct sockaddr_in *info4 = it->ai_addr;
        char ip[INET_ADDRSTRLEN + 1]="";
        inet_ntop(AF_INET, &(info4->sin_addr), ip, INET_ADDRSTRLEN + 1);
				printf("%s\t",ip);
      break;
      case AF_INET6:;
        struct sockaddr_in6 *info6 = it->ai_addr;
        char ipv6[INET6_ADDRSTRLEN + 1]="";
        inet_ntop(AF_INET6, &(info6->sin6_addr), ipv6, INET6_ADDRSTRLEN + 1);
				printf("%s\t",ipv6);
      break;
    }
	getnameinfo(addr, addrlen, hbuf, sizeof(hbuf), sbuf,
                       sizeof(sbuf), NI_NUMERICHOST | NI_NUMERICSERV);
               printf("host=%s", hbuf);


	printf("%i\t%i\t\n",it->ai_family, it->ai_socktype);
	}
	
freeaddrinfo(result);


  return 0;
}
