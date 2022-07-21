#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	char Fname[20];
	char Data[100];
	int iRet = 0;

	int fd = 0;		//file descriptor

	printf("Enter File Name To Create\n");
	scanf("%s",Fname);

	printf("Enter the data that you want to write :\n");
	scanf(" %[^'\n']s",Data);

	fd = creat(Fname,0777);		//0777 is octal no(0 prefix for octal & 0X for HeaxaDecimal)
						// so in properties we can see there are 3 users in security owner group other
						// 0 for octal prefix || 7 for permissions for owner || 7 for group || 7 for other
						//  4 - read   2 - write   1 - execute(4+2+1 = 7)
						// means owner,group,other can do all tasks
						// for ex - 0764
						// 0 for octal prefix || 7(all task) for permissions for owner || 6(4+2,read write) for group || 4(read) for other
						
						

	if(fd == -1)	// fd returns -1 if file is not created
	{
		printf("Unable To create File\n");
		return -1;
	}

	printf("File Is Successfully Created With FD %d\n",fd);	// it gives 3 they are users (owner,group,other)

	iRet = write(fd,Data,strlen(Data));		// this will return how many byte is written
	printf("%d bytes successfully written in the file\n",iRet);

	return 0;
}