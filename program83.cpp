// hpw to travers string using for loop

#include<iostream>

using namespace std;

void Display(char *str)
{

	while(*str != '\0')
	{
		cout<<*str<<endl;
		str++;
	}

	//int i = 0;

	//while(str[i] != '\0')
	//
	//	cout<<str[i]<<endl;
	//	i++;
	//}
}

int main()
{
	char Arr[] = "Hello";

	Display(Arr);	//Display(100) call by address

	return 0;
	
}