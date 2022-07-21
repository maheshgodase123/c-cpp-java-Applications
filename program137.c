// accept string from user and count its small chracters

#include<stdio.h>


int CountSmallI(char *str)
{
	int Cnt = 0;

	while(*str != '\0')
	{
		if(*str >= 'a' && *str <= 'z')
		{
			Cnt++;
		}
		str++;
	}

	return Cnt;
}

int CountSmallR(char *str)
{
	static int Cnt = 0;

	if(*str != '\0')
	{
		if(*str >= 'a' && *str <= 'z')
		{
			Cnt++;
		}
		str++;	// ithe str pudhcya element la point krel

		CountSmallR(str);		// ani ithe mi str update kelela pathvtoy
	}

	return Cnt;
}

int main()
{
	char Arr[20];
	int iRet = 0;

	printf("Enter The String\n");	
	scanf("%[^'\n']s", Arr);
	
	iRet = CountSmallR(Arr);

	printf("Small Characters Are : %d\n",iRet);	

	return 0;
}