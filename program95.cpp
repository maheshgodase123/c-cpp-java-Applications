// Accept string from user and change string to Upper case

#include<iostream>

using namespace std;

void StruprX(char *str)
{
	int iCnt = 0;

	while(*str != '\0')
	{
		if((*str >= 'a') && (*str <= 'z'))
		{
			*str = *str - 32;	// bcoz every ascii values of small and capital character differ by 32
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

	StruprX(Arr);

	cout<<"String In Upper Is : "<<Arr<<endl;	// bcoz its call by adress so changes reflect directly to main

	return 0;
	
}