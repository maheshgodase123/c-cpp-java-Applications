// program to open the existing file

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

// O_RDONLY  Read
// O_WRONLY Write
// O_RDWR  Read And Write

int main()
{
	char Fname[20];
	int iRet = 0;

	int fd = 0;		//file descriptor

	printf("Enter File Name To Open\n");
	scanf("%s",Fname);

	fd = open(Fname,O_RDONLY);	// telling os to read only file		
						

	if(fd == -1)	// fd returns -1 if file is not created
	{
		printf("Unable To Open File\n");
		return -1;
	}

	printf("File Is Successfully Open With FD %d\n",fd);	// it gives 3 they are users (owner,group,other)



	return 0;
}