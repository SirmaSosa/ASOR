#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
int main(){
        for(int i=0;i<255;i++){
        printf("Error %d %s \n",i,strerror(i));
        }
        return 1;
}
