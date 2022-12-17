#include <stdio.h>
#include <unistd.h>
#include <errno.h>


int main() {

	int p_h[2];
	int h_p[2];
	pipe(p_h);
	pipe(h_p);
	int pid = fork();
	if (pid == 0) {
		close(p_h[1]);
		close(h_p[0]);
		for (size_t i = 0; i < 10; i++) {
			ssize_t b = read(p_h[0], msgP, 255);
			msgP[bytes] = '\0';
			printf("[HIJO] Recibido: %s\n", mensajePadre);
			sleep(1);
			if (i == 9) flag = 'q';
			write(h_p[1], &flag, 1);
		}
	}
	if (pid == 1) {
		close(p_h[0]);
		close(h_p[1]);
		while (stop != 'q') {
			printf("%s\n", "[PADRE] Mensaje: ");
			ssize_t b = read(0, msg, 255);
			msg[b] = '\0';
			write(p_h[1], msg, 255);
			read(h_p[0], &flag, 1);
		}
		wait(NULL);
		close(fd[1]);
		close(fd[0]);
		printf("10 mensajes enviados con éxito. Saliendo... \n");
		break;
	}
}