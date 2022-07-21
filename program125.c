// program to open the file and read the file

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

// O_RDONLY  Read
// O_WRONLY Write
// O_RDWR  Read And Write	(// this can be write to read or write or read and write data)

int main()
{
	char Fname[20];
	char Data[100];
	int iRet = 0;

	int fd = 0;		//file descriptor

	printf("Enter File Name To Open\n");
	scanf("%s",Fname);

	fd = open(Fname,O_RDWR);	// telling os to read and write only file		
						

	if(fd == -1)	// fd returns -1 if file is not created
	{
		printf("Unable To Open File\n");
		return -1;
	}

	printf("File Is Successfully Open With FD %d\n",fd);	

	iRet = read(fd,Data,10);		//(kuthe lihaychay, kay lihaychay, kity lihaychay)

	printf("%d bytes of the Data Is Successfully Read!!\n",iRet);	// here data will be overwritten bt if prev data is 15 byte
												// and you write new data of 5 bytes so it will overwrite only 1st 5 bytes
	printf("Data From File Is : %s\n",Data);
	write(1,Data,iRet);	//this can be use to write the data //1-> STDOUT
	
	return 0;
}

// Reserved Data Descriptor

// 0	STDIN		KeyBoard
// 1  STDOUT	Monitor
// 2	STDERR	Monitor