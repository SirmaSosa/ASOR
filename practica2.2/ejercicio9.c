#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/sysmacros.h>
#include <unistd.h>
int main(int argc,char**argv){
	struct stat data;
	stat(argv[1],&data);
	printf("Major %li\n Minor %li\n,",(long)major(data.st_dev),(long)minor(data.st_dev));
	printf("El numero de inodo es %ld",data.st_ino);
	if(S_ISREG(data.st_mode))
		printf("Es un fichero regular");
	else if(S_ISDIR(data.st_mode))
		printf("Es un directorio");
	else if(S_ISLNK(data.st_mode))
		printf("Es un enlace simbolico");

}
