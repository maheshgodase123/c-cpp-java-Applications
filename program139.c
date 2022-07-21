// input = 6
// output = a b c d e f

#include<stdio.h>

void Display(int iNo)
{
	char ch = 'a';
	int i = 0;

	while(i < iNo)
	{
		printf("%c\t",ch);
		ch++;
		i++;
	}
}

void DisplayR(int iNo)
{
	static char ch = 'a';

	if(iNo > 0)
	{
		printf("%c\t",ch);
		ch++;
		iNo--;

		DisplayR(iNo);
	}
}

int main()
{
	int iValue = 0;

	printf("Enter The Value : \n");
	scanf("%d",&iValue);

	DisplayR(iValue);

	return 0;
}