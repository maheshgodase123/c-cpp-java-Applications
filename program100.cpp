// Accept two string and compare two strings 

#include<iostream>

using namespace std;

bool StrcmpX(char *src,char *dest)	// src=source,dest=destination
{

	while((*src != '\0') && (*dest != '\0'))	
	{
		if(*dest != *src)
		{
			break;
		}
		
		src++;
		dest++;
	}

	if((*src == '\0') && (*dest == '\0'))
	{
		return true;
	}
	else
	{
		return false;
	}

}

int main()
{
	char Arr[20];
	char Brr[20];
	bool bret = false;

	cout<<"Enter 1st String : "<<endl;
	cin.getline(Arr,20);

	cout<<"Enter 2nd String : "<<endl;
	cin.getline(Brr,20);

	bret = StrcmpX(Arr,Brr);

	if(bret == true)
	{
		cout<<"String 1st And 2nd Are Same"<<endl;
	}
	else
	{
		cout<<"String 1st And 2nd Are Not Same"<<endl;
	}
	

	return 0;
	
}