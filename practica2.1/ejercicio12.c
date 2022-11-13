#include <time.h>
#include <stdio.h>

int main(){
        time_t tiempo = time(NULL);
        printf("Han pasado %ld segundos \n",tiempo);
}
