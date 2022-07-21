#include<iostream>

using namespace std;

int strlenX(char *str)
{
	int iCnt = 0;

	while(*str != '\0')
	{
		cout<<*str<<endl;
		str++;
		iCnt++;
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

	cout<<"Length Is : "<<iRet<<endl;

	return 0;
	
}