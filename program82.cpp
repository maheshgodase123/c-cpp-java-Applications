// hpw to travers string using for loop

#include<iostream>

using namespace std;

int main()
{
	char Arr[] = "Hello";

	for(int i = 0; Arr[i] != '\0'; i++)
	{
		cout<<Arr[i]<<endl;
	}

	return 0;
	
}