#include<iostream>

using namespace std;

int strlenX(char *str)
{
	int iCnt = 0;

	while(*str != '\0')
	{
		if(*str == 'l' || *str == 'L')
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
	//cin>>Arr;
	//scanf("%[^'\n']s",Arr);	// jo paryant enter hot nahi toparyant string input ghe
	cin.getline(Arr,20);

	iRet = strlenX(Arr);	//Display(100) call by address

	cout<<"Occurence Of l/L Count Is : "<<iRet<<endl;

	return 0;
	
}