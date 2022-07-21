// accept file name from users and count the length(characters) of the data of file 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

// O_RDONLY  Read
// O_WRONLY Write
// O_RDWR  Read And Write	(// this can be write to read or write or read and write data)

int FileLength(char Fname[])
{
	char Data[10];
	int sum = 0;

	int length = 0;

	int fd = 0;	

	fd = open(Fname,O_RDWR);
						

	if(fd == -1)
	{
		printf("Unable To Open File\n");
		return -1;
	}

	printf("File Is Successfully Open With FD %d\n",fd);	

	while((sum = read(fd,Data,sizeof(Data))) != 0)		
	{
		length += sum;	// ha kity read krto return krto iRet so mg tich apli length ahe
	}
	
	close(fd);

	return length;

}

int main()
{
	char Fname[20];
	int iRet = 0;

	printf("Enter File Name To Open\n");
	scanf("%s",Fname);

	iRet = FileLength(Fname);

	printf("File Length Is : %d\n",iRet);

	return 0;
}

// Reserved Data Descriptor

// 0	STDIN		KeyBoard
// 1  STDOUT	Monitor
// 2	STDERR	Monitor

