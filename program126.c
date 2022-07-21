// Accept The File From The User And Read The Whole Data 

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
	char Data[10];
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

	while((iRet = read(fd,Data,sizeof(Data))) != 0)		// this will read data unti
	{
		write(1,Data,iRet);	//(kay karaychay(STDOUT), kashyamadhala karaychay, kity karaychay(Bytes))
	}
	
	// vrchya while madhe 
	// apla loop size of data joparyant iRet madhe 0 yet nahi toparyant run honar
	// 10 10 6 loop band(26 letters astat)
  
	close(fd);
	return 0;
}

// Reserved Data Descriptor

// 0	STDIN		KeyBoard
// 1  STDOUT	Monitor
// 2	STDERR	Monitor