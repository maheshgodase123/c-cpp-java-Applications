// Accept string and copy in another string

#include<iostream>

using namespace std;

void StrcpyX(char *src,char *dest)	// src=source,dest=destination
{
	while(*src != '\0')	// mi ithe "\0" lihila hota error deto cpp
					// karan string yamadhe lihitat ani char '' madhe
	{
		*dest = *src;
		
		src++;
		dest++;
	}

	*dest = '\0';	// karan \0 la loop thambla toh copy nahi zala pn tohi garjecha ahe mg explitcitly khali lihila 
}

int main()
{
	char Arr[20];	// Bharleli Wahi
	char Brr[20];	// Kori wahi (mnje hyat copy karaychay)

	cout<<"Enter String : "<<endl;
	cin.getline(Arr,20);

	StrcpyX(Arr,Brr);

	cout<<"String After Copy Is : "<<Brr<<endl;	// bcoz its call by adress so changes reflect directly to main

	return 0;
	
}