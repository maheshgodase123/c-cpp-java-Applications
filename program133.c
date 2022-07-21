// Aceept The Two File Names (Existenng) and compare the data

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<fcntl.h>
#include<string.h>

#define FILESIZE 1024
 
bool FileCompare(char Source[], char Destination[])
{
	int Fdsrc = 0, Fddest = 0, iRet1 = 0, iRet2 = 0;

	char Buffer1[FILESIZE];
	char Buffer2[FILESIZE];  

	Fdsrc = open(Source, O_RDONLY);	// pahile ji copy karaychiye ti open kara

	if(Fdsrc == -1)
	{
		printf("Unable To Open Source File\n");
		return false;
	}

	Fddest = open(Destination,O_RDONLY);
	if(Fddest == -1)
	{
		printf("Unable To Open Destination File\n");
		return false;
	}


	while(1)
	{
		iRet1 = read(Fdsrc,Buffer1,FILESIZE);
		iRet2 = read(Fddest,Buffer2,FILESIZE);

		if((iRet1 == 0) || (iRet2 == 0) || (iRet1 != iRet2))
		{
			break;
		}
		int iCmp = memcmp(Buffer1,Buffer2,iRet1);		// internally for loopch ahe ha apla letter to letter check krnar
		if(iCmp != 0)
		{
			break;
		}
	}
	
	close(Fdsrc);
	close(Fddest);

	if((iRet1 == 0) && (iRet2 == 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	char Fname1[20];
	char Fname2[20];
	bool Bret;

	printf("Enter File Name Which Contains The Data\n");
	scanf("%s", Fname1);

	printf("Enter 2nd File Which Contains Data And You Want Copy In\n");
	scanf("%s", Fname2);

	Bret = FileCompare(Fname1,Fname2);

	if(Bret == true)
	{
		printf("File are Identicle\n");
	}
	else
	{
		printf("Files Are Different\n");
	}

	return 0;
}