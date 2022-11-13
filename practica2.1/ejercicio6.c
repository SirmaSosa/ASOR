#include <unistd.h>
#include <stdio.h>

int main() {
        printf("Long MAX: %li\n", sysconf(_SC_ARG_MAX));
        printf("N MAX hijos: %li\n", sysconf(_SC_CHILD_MAX));
        printf("N MAX ficheros: %li\n", sysconf(_SC_OPEN_MAX));
        return 0;
}

