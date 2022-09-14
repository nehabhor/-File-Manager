//lseek function count the letter from txt file before 10letters

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdbool.h>
#include<string.h>

int main()
{
	char fname[20];
    char Data[10];
	int fd=0;
	
	printf("Enter the file name\n");
	scanf("%s",fname);
	 
    fd= open(fname,O_RDONLY);
	 if(fd==-1)
	 {
		 printf("Unable to open file");
		 return -1;
	 }
	 
	 lseek(fd,10,0);
	 
	 read(fd,Data,5);
	 write(1,Data,5);
	 
	return 0;
}