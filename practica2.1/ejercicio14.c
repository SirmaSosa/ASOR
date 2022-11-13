#include <time.h>
#include <sys/time.h>
#include <stdio.h>
int main(){
        time_t tiempo = time(NULL);
        struct tm *info = localtime(&tiempo);
        int year = info->tm_year;
        printf("Estamos en el año: %i\n", 1900 + year);
  return 1;
}
