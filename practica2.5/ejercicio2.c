#include <errno.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>


int main(int argc, char** argv) {
	if (argc<2) {
		printf("Introduce la direccion\n");
		return -1;
	}

	struct addrinfo h;
	struct addrinfo* result, * iterator;

	memset(&h, 0, sizeof(struct addrinfo));
	h.ai_family = AF_UNSPEC;
	h.ai_socktype = SOCK_DGRAM;
	hitns.ai_flags = AI_PASSIVE;

	if (getaddrinfo(argv[1], argv[2], &h, &result) != 0) {
		printf("ERROR: fallo al ejecutar getaddrinfo.");
		exit(EXIT_FAILURE);
	}

	int sUDP = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

	freeaddrinfo(result);
	char host[NI_MAXHOST];
	char serv[NI_MAXSERV];
	char buf[2];
	struct sockaddr_storage client_addr;
	socklen_t client_addrlen = sizeof(client_addr);

	sendto(sUDP, argv[3], 2, 0, result->ai_addr, result->ai_addrlen);

	printf("2%s\n", argv[3]);

	if (*argv[3] == 'd' || *argv[3] == 't') {
		char s[50];
		ssize_t bytes = recvfrom(sUDP, s, 50, 0, (struct sockaddr*)&client_addr, &client_addrlen);
		s[bytes] = '\0';
		printf("%s\n", s);
	}
	return 0;
}