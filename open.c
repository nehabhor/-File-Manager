//Open the file

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
	
	printf("Enter the file name to open\n");
	scanf("%s",fname);
	
	fd=open(fname,O_RDWR | O_APPEND);
	if(fd==-1)//failure
	{
		printf("Unable to open the file\n");
		return -1;
	}
	printf("file successfully opened with FD %d\n",fd);
	
	iRet=read(fd,Data,4);
	
	printf("%d bytes gets successfully read the file\n",iRet);
	
	printf("Data from the file is \n");
	write(1,Data,iRet);
	
	return 0;
}