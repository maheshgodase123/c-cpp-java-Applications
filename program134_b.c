// Aceept The File Name (Existenng) and read the last 5 bytes after the 10 bytes data

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<fcntl.h>		//mnje file controll
#include<string.h>


int main()
{
	char Fname[20];
	int Fd = 0;
	char Data[10];

	printf("Enter File Name\n");
	scanf("%s", Fname);

	Fd = open(Fname,O_RDONLY);
	if(Fd == -1)
	{
		printf("Unable To Open File!!");
		return -1;
	}

	//0  Starting Point
	//1  Current Position
	//2  End Point
	// below Are the third parameter of lseek i.t from where u are going to skip data

	lseek(Fd,-5,2);	//(kashat pudhe jaychay,kiti pudhe jaychay,kuthun survat)inbuild function
	//(ithe 2 mnje apan last pasun surwat krtoy -5 mnje last five)

	read(Fd,Data,5);
	write(1,Data,5);

	return 0;
}