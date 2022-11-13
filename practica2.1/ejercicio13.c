#include <sys/time.h>
#include <stdio.h>

int main(){
        struct timeval tIni;
                int aux = gettimeofday(&tIni,NULL);
        int inicio = tIni.tv_usec;
        for(int i=0; i<1000000; i++);
        struct timeval tFin;
                int aux2 = gettimeofday(&tIni,NULL);
        int final = tFin.tv_usec;

        printf("Tarda: %i\n",final-inicio);

        return 1;
}
