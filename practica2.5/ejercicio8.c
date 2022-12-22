#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

int main(int argc, char** argv) {

    if (argc < 2) {
        printf("Introduce los parámetros\n");
        return -1;
    }

    struct addrinfo h;
    struct addrinfo* result;

    memset(&h, 0, sizeof(struct addrinfo));
    h.ai_family = AF_UNSPEC;
    h.ai_socktype = SOCK_STREAM;
    h.ai_flags = AI_PASSIVE; 

    if (getaddrinfo(argv[1], argv[2], &h, &result) != 0) {
        printf("ERROR: error al ejecutar getaddrinfo.");
        exit(EXIT_FAILURE);
    }

    int sTCP = socket(result->ai_family, result->ai_socktype, 0);
    bind(sTCP, result->ai_addr, result->ai_addrlen);
    freeaddrinfo(result);

    listen(sTCP, 5);

    struct sockaddr_storage cli;
    socklen_t clen = sizeof(cli);
    char buf[81];
    int cli_sd;
    ssize_t c;
    char host[NI_MAXHOST];
    char serv[NI_MAXSERV];
    while (1) {
        cli_sd = accept(sTCP, (struct sockaddr*)&cli, &clen);
        pid_t pid;
        pid = fork();
        if (pid == 0) {
            while (1) {
                getnameinfo((struct sockaddr*)&cli, clen, host, NI_MAXHOST, serv, NI_MAXSERV, NI_NUMERICHOST);
                printf("[PID: %i] Conexión desde %s:%s\n", getpid(), host, serv);
                c = recv(cli_sd, buf, 80, 0);
                buf[c] = '\0';
                if ((buf[0] == 'Q') && (c == 2)) {
                    printf("Conexión finalizada\n");
                    break;
                }
                send(cli_sd, buf, c, 0);
            }
            close(cli_sd);
        }
        else close(cli_sd);
    }
    close(cli_sd);
    return 0;
}