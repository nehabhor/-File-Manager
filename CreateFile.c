//Creating the file

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

//Read:4
//write:2 
//Execute:1

//permission 0_Owner_Group_Other

int main()
{
	char fname[20];
	int fd=0; //File descriptor
	
	printf("enter file name to create\n");
	scanf("%s",fname);
	
	fd=creat(fname,0777);
	if(fd==-1)//failure
	{
		printf("Unable to create the file\n");
		return -1;
	}
	printf("Successfully create the fd %d\n",fd);
	return 0;
}