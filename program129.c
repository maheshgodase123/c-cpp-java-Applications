// accept file name from users and count the Capital characters of the file 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

// O_RDONLY  Read
// O_WRONLY Write
// O_RDWR  Read And Write	(// this can be write to read or write or read and write data)

int CountCapital(char Fname[])
{
	char Data[1024];	//
	int CountCap = 0;
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
			if(Data[i] >= 'A' && Data[i] <= 'Z')
			{
				CountCap++;
			}
		}
	}
	
	close(fd);

	return CountCap;;

}

int main()
{
	char Fname[20];
	int iRet = 0;

	printf("Enter File Name To Open\n");
	scanf("%s",Fname);

	iRet = CountCapital(Fname);

	printf("No Of Capital Characters In File Is : %d\n",iRet);

	return 0;
}

// Reserved Data Descriptor

// 0	STDIN		KeyBoard
// 1  STDOUT	Monitor
// 2	STDERR	Monitor

