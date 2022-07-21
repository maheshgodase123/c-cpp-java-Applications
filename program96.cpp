// Accept string from user and toggle the case(A->a, a->A)

#include<iostream>

using namespace std;

void StrtoggleX(char *str)
{
	int iCnt = 0;

	while(*str != '\0')
	{
		if((*str >= 'a') && (*str <= 'z'))
		{
			*str = *str - 32;	// bcoz every ascii values of small and capital character differ by 32
		}
		else if((*str >= 'A') && (*str <= 'Z')) // we have to write else if bcoz str can contains int or special char
		{
			*str = *str + 32;	// bcoz every ascii values of small and capital character differ by 32
		}
		str++;
	}
	
}

int main()
{
	char Arr[20];
	int iRet = 0;

	cout<<"Enter String : "<<endl;
	cin.getline(Arr,20);

	StrtoggleX(Arr);

	cout<<"String to Toggle Is : "<<Arr<<endl;	// bcoz its call by adress so changes reflect directly to main

	return 0;
	
}