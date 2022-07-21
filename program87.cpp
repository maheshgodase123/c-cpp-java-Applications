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
	// jrr mi space wali string dili (ex-hello world) trr fakt hello ch print hota
	
	//int i = 0;

	//while(str[i] != '\0')
	//
	//	cout<<str[i]<<endl;
	//	i++;
	//}
}

int main()
{
	char Arr[20];

	cout<<"Enter String : "<<endl;
	//cin>>Arr;
	//scanf("%[^'\n']s",Arr);	// jo paryant enter hot nahi toparyant string input ghe
	cin.getline(Arr,20);

	Display(Arr);	//Display(100) call by address

	return 0;
	
}