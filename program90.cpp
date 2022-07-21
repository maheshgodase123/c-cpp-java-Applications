// Accept string from user and count no of capital characters

#include<iostream>

using namespace std;

int CountCapital(char *str)
{
	int iCnt = 0;

	while(*str != '\0')
	{
		if(*str >= 'A' && *str<= 'Z')	// (*str >=65  && *str<= 90) using ascii value
		{
			iCnt++;
		}

		str++;
	}
	
	return iCnt;
}

int main()
{
	char Arr[20];
	int iRet = 0;

	cout<<"Enter String : "<<endl;
	cin.getline(Arr,20);

	iRet = CountCapital(Arr);

	cout<<"String Contains Capital Count Is : "<<iRet<<endl;

	return 0;
	
}