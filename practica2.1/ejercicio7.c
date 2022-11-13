#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/utsname.h>
#include <sys/types.h>

int main() {
        printf("N MAX enlaces: %li\n", pathconf("/",_PC_LINK_MAX));
        printf("Tam MAX ruta: %li\n", pathconf("/",_PC_PATH_MAX));
        printf("Tam MAX nombre fichero: %li\n", pathconf("/",_PC_NAME_MAX));
        return 1;
}
