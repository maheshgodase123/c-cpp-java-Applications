// Aceept The Two File Names (Existenng) and copy the 1 file and append to it

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

#define FILESIZE 1024
 
void FileConcat(char Source[], char Destination[])
{
	int Fdsrc = 0, Fddest = 0, iRet = 0;

	char Buffer[FILESIZE]; 	// ha apla data variable ahe pn tyala buffer mhantat

	Fdsrc = open(Source, O_RDONLY);	// pahile ji copy karaychiye ti open kara

	if(Fdsrc == -1)
	{
		printf("Unable To Open Source File\n");
		return;
	}

	Fddest = open(Destination,O_RDWR | O_APPEND);
	if(Fddest == -1)
	{
		printf("Unable To Open Destination File\n");
		return;
	}

	write(Fddest,' ',1);
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

	printf("Enter 2nd File Which Contains Data And You Want Copy In\n");
	scanf("%s", Fname2);

	FileConcat(Fname1,Fname2);

	return 0;
}