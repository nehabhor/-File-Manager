//Compare the 2 files

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdbool.h>
#include<string.h>

#define FILESIZE 1024

bool FileCompare(char Source[],char Dest[])
{
	int fdsrc=0,fddest=0,i=0,iCnt=0,iCmp=0;
	int iRet1=0,iRet2=0;
	
	char Buffer1[FILESIZE];
	char Buffer2[FILESIZE];
	
	fdsrc= open(Source,O_RDONLY);
	if(fdsrc==-1)
	{
		printf("Unable to open source file\n");
		return false;
	}
	
	fddest= open(Dest,O_RDONLY);
	if(fddest==-1)
	{
		printf("Unable to open dest file\n");
		return false;
	}
	while(1)
	{
		iRet1=read(fdsrc,Buffer1,FILESIZE);
		iRet2=read(fddest,Buffer2,FILESIZE);
		
		if((iRet1==0)||(iRet2==0)||(iRet1!=iRet2))
		{
			break;
		}
		iCmp=memcmp(Buffer1,Buffer2,iRet1);
		if(iCmp!=0)
		{
			break;
		}
	}
	
	close(fdsrc);
	close(fddest);
	if((iRet1==0) && (iRet2==0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	char fname1[20];
    char fname2[20];
	bool BRet; 
	
	printf("Enter the file which contains the data\n");
	scanf("%s",fname1);
	
	
	printf("Enter the file which contains the create\n");
	scanf("%s",fname2);
	
	BRet=FileCompare(fname1,fname2);
	if(BRet==true)
	{
		printf("Files are same\n");
	}
	else
	{
		printf("Files are different");
	}
	
	return 0;
}