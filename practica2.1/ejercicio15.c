#include <sys/time.h>
#include <time.h>
#include <stdio.h>
int main(){

        time_t tiempo = time(NULL);
        struct tm *info = localtime(&tiempo);
        int year = info->tm_year;
        int day = info->tm_mday;
        int month = info->tm_mon;
        struct tm *timedata = localtime(&tiempo);
        char buf[100];
        strftime(buf,100, "%A, %H:%M", timedata);
        printf("%s\n",buf);
  return 1;
}
