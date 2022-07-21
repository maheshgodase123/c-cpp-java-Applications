// accept file name from users and count the small characters of the file 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

// O_RDONLY  Read
// O_WRONLY Write
// O_RDWR  Read And Write	(// this can be write to read or write or read and write data)

int CountSmall(char Fname[])
{
	char Data[1024];	// 10 denyamule os la sarkha hdd vrr jayla lagta mhanu n akdach 1kb size dyaychi 
	int CountSmall = 0;
	int iRet = 0;

	int length = 0;

	int fd = 0;	

	fd = open(Fname,O_RDWR);
						

	if(fd == -1)
	{
		printf("Unable To Open File\n");
		return -1;
	}

	while((iRet = read(fd,Data,sizeof(Data))) != 0)		
	{
		for(int i=0; i<iRet; i++)
		{
			if(Data[i] >= 'a' && Data[i] <= 'z')
			{
				CountSmall++;
			}
		}
	}
	
	close(fd);

	return CountSmall;;

}

int main()
{
	char Fname[20];
	int iRet = 0;

	printf("Enter File Name To Open\n");
	scanf("%s",Fname);

	iRet = CountSmall(Fname);

	printf("No Of Small Characters In File Is : %d\n",iRet);

	return 0;
}

// Reserved Data Descriptor

// 0	STDIN		KeyBoard
// 1  STDOUT	Monitor
// 2	STDERR	Monitor

