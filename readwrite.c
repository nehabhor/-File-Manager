#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>


int main()
{
	char fname[20];
	char Data[100];
	
	int iRet=0;
	int fd=0; //File descriptor
	
	printf("enter file name to open\n");
	scanf("%s",fname);
	
	fd=open(fname,O_RDWR);
	if(fd==-1)//failure
	{
		printf("Unable to create the file\n");
		return -1;
	}
	printf("file successfully opened with FD %d\n",fd);
	
	printf("Enter the data that you want to write:\n");
	scanf("% [^'\n']s",Data);
	
	iRet=write(fd,Data,strlen(Data));
	
	printf("%d bytes gets successfully written in the file\n",iRet);
	
	return 0;
}