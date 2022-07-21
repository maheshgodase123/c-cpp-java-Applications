// program to open the file and write the file

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
	char Data[100];
	int iRet = 0;

	int fd = 0;		//file descriptor

	printf("Enter File Name To Open\n");
	scanf("%s",Fname);

	fd = open(Fname,O_RDWR | O_APPEND);	// here we are appending 		
						

	if(fd == -1)	// fd returns -1 if file is not created
	{
		printf("Unable To Open File\n");
		return -1;
	}

	printf("File Is Successfully Open With FD %d\n",fd);	

	printf("Enter The Data That You Want To Writr : \n");
	scanf(" %[^'\n']s",Data);

	iRet = write(fd,Data,strlen(Data));		//(kuthe lihaychay, kay lihaychay, kity lihaychay)

	printf("%d bytes of the Data Is Successfully Writen!!\n",iRet);
	

	return 0;
}