#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/utsname.h>
#include <sys/types.h>
int main(){
       struct utsname info;
  if (uname (&info) == -1){
           
     printf("Error%d: %s\n", errno, strerror(errno));
     return -1;
        } else {
    printf("Nombre del Sistema: %s\n", info.sysname);
    printf("Nodename: %s\n", info.nodename);
    printf("Release: %s\n", info.release);
    printf("Version: %s\n", info.version);
    printf("Machine: %s\n", info.machine);
  }
  return 1;
}

