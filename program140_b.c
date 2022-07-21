#include<stdio.h>

void Display(char *str)
{
	while(*str != '\0')
	{
		printf("%c\n",*str);
		str++;
	}
}

void DisplayR(char *str)
{
	if(*str != '\0')
	{
		//DisplayR(str++);   this will give you infinite loop bcoz adhi increment karaychya adhich apan str pathavtoy
		// mhanun mg call Display(100) mg prt Display(100) ani asach janar karan increment ahe toh adhi no jatiye
	

		// printf(str) and DisplayR(++str);	asa format manje tail recursion mnje print krt krt mage jato
		DisplayR(str+1);		// he head recursion ahe adhi last stack frame paryant jail mg magun print krt yeil reverse krel 

		printf("%s\n",str);		// %s mule akhi string display hoil /0 paryant
	}
}


int main()
{
	char Arr[20];

	printf("Enter String\n");
	scanf("%[^'\n']s",Arr);

	DisplayR(Arr);

	return 0;
}