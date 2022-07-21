// Accept string and perform concatination(yachya adhi 98 bgh)

#include<iostream>

using namespace std;

void StrcatX(char *src,char *dest)	// src=source,dest=destination
{
	while(*dest != '\0')
	{
		dest++;
	} 
	// ithe apan dest madhe end address ala

	while(*src != '\0')	
	{
		*dest = *src;
		
		src++;
		dest++;
	}

	*dest = '\0';	// karan \0 la loop thambla toh copy nahi zala pn tohi garjecha ahe mg explitcitly khali lihila 
}

// apan vrti src madhech takliye dest string mnje arr madhe brr takli
// ulta pn kru shakto fakt vrcha logic khali ani khalcha vrr lihav lagel

int main()
{
	char Arr[20];
	char Brr[20];

	cout<<"Enter 1st String : "<<endl;
	cin.getline(Arr,20);

	cout<<"Enter 2nd String : "<<endl;
	cin.getline(Brr,20);

	StrcatX(Arr,Brr);

	cout<<"String After Concatination Is : "<<Brr<<endl;

	return 0;
	
}