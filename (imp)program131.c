#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

#define FILESIZE 1024
 
void FileCopy(char Source[], char Destination[])
{
	int Fdsrc = 0, Fddest = 0, iRet = 0;

	char Buffer[FILESIZE]; 	// ha apla data variable ahe pn tyala buffer mhantat

	Fdsrc = open(Source, O_RDONLY);	// pahile ji copy karaychiye ti open kara

	if(Fdsrc == -1)
	{
		printf("Unable To Open Source File\n");
		return;
	}

	Fddest = creat(Destination,0777);
	if(Fddest == -1)
	{
		printf("Unable To Create New File\n");
		return;
	}

	while((iRet = read(Fdsrc,Buffer,FILESIZE)) != 0)
	{
		write(Fddest,Buffer,iRet);	// adhi 1 hota mnje monitor vrr liha ata Fddest mdhe liha 
	}
	
	close(Fdsrc);
	close(Fddest);
}

int main()
{
	char Fname1[20];
	char Fname2[20];

	printf("Enter File Name Which Contains The Data\n");
	scanf("%s", Fname1);

	printf("Enter FIle Name You Want To Create\n");
	scanf("%s", Fname2);

	FileCopy(Fname1,Fname2);

	return 0;
}