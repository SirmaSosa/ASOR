#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
int main(){
        if(setuid(0)==-1){
        int x =errno;
        printf("Error%d:%s \n",x,strerror(x));}
        return 1;
}
