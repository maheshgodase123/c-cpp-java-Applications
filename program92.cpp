// Accept string from user and count no of small characters

#include<iostream>

using namespace std;

int CountSpace(char *str)
{
	int iCnt = 0;

	while(*str != '\0')
	{
		if(*str == ' ')	// (*str = 32) using ascii value
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

	iRet = CountSpace(Arr);

	cout<<"String Contains Spaces Count Is : "<<iRet<<endl;

	return 0;
	
}