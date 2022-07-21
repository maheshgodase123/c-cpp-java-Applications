// Accept string from user and change string to lower case

#include<iostream>

using namespace std;

void StrlwrX(char *str)
{
	int iCnt = 0;

	while(*str != '\0')
	{
		if((*str >= 'A') && (*str <= 'Z'))
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

	StrlwrX(Arr);

	cout<<"String In Lower Is : "<<Arr<<endl;	// bcoz its call by adress so changes reflect directly to main

	return 0;
	
}