#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	char fname[20];
	char Data[100];
	int fd=0; //File descriptor
	
	printf("enter file name to create\n");
	scanf("%s",fname);
	
	printf("enter the date that you want to write\n");
	scanf(" %[^'\n']s",Data);
	
	fd=creat(fname,0777);
	if(fd==-1)//failure
	{
		printf("Unable to create the file\n");
		return -1;
	}
	printf("Successfully create the fd %d\n",fd);
	
	write(fd,Data,strlen(Data));
	
	return 0;
}