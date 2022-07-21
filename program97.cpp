// Accept string and reverse the string INPLACE(mnje tithlyatithe mnje tych memory madhe)

#include<iostream>

using namespace std;

void StrrevX(char *str)
{
	int iCnt = 0;

	char *start = str;
	char *end = str;
	char swap;

	while(*end != '\0')	// to obtained the address of last element in end
	{
	
		end++;
	}
	end--;	// bcoz after while end will contained address of '\0'

	// now time to swap char at inplace

	while(start < end)
	{
		char swap = *start;
		*start = *end;
		*end = swap;

		start++;
		end--;
	}

	 
	
}

int main()
{
	char Arr[20];
	int iRet = 0;

	cout<<"Enter String : "<<endl;
	cin.getline(Arr,20);

	StrrevX(Arr);

	cout<<"String After Reverse Is : "<<Arr<<endl;	// bcoz its call by adress so changes reflect directly to main

	return 0;
	
}