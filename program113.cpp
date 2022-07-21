#include<iostream>

using namespace std;

void swapA(int *no1, int *no2)	// call by address function
{
	int temp;
	temp = *no1;
	*no1 = *no2;
	*no2 = temp;
}

void swapR(int &no1, int &no2)	// call by reference function
{
	int temp;
	temp = no1;
	no1 = no2;
	no2 = temp;
}

int main()
{
	int value1 = 11,value2=20;

	cout<<"Before Swap Data Is : "<<value1<<" "<<value2<<endl;

	swapA(&value1, &value2);	// call by address

	cout<<"After Swap Data Is(using call by address) : "<<value1<<" "<<value2<<endl;

	swapR(value1, value2);		// call by reference this will again swap 

	cout<<"After Swap Data Is(using call by reference) : "<<value1<<" "<<value2<<endl;


	return 0;
}