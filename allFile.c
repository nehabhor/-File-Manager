//Display all files to user

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	char fname[20];
	char Data[10]; //Mug
	
	int iRet=0;
	int fd=0; //File descriptor
	
	printf("Enter the file name to open\n");
	scanf("%s",fname);
	
	fd=open(fname,O_RDWR);
	if(fd==-1)//failure
	{
		printf("Unable to open the file\n");
		return -1;
	}
	printf("file successfully opened with FD %d\n",fd);
	
	while((iRet = read(fd,Data,sizeof(Data)))!=0)
		
		{
			write(1,Data,iRet);
		}
		close(fd);
		
	return 0;
}