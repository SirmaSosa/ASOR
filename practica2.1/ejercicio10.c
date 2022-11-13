#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/utsname.h>
#include <sys/types.h>
#include <pwd.h>

int main(){
        uid_t uid = getuid();

        printf("UID Real: %d\n", getuid());
        printf("UID efectivo: %d\n", geteuid());
        struct passwd *pass= getpwuid(uid);

        char *nombre = pass->pw_name;
        char *direccion = pass->pw_dir;
        char *informacion = pass->pw_gecos;

        printf("Usuario: %s\n", nombre);
        printf("Home: %s\n", direccion);
        printf("Info: %s\n",informacion);
        return 1;
}
