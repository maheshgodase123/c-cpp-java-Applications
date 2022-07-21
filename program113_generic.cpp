#include<iostream>

using namespace std;

template<class T>

void swapR(T &no1, T &no2)	// call by reference function
{
// mnje T chair sarkha ahe tithe konihi yeun basu shakto(int kiva char kiva )
	T temp;
	temp = no1;
	no1 = no2;
	no2 = temp;
}

int main()
{
	// for int value

	int value1 = 11,value2=21;
	cout<<"Before Swap Data Is : "<<value1<<" "<<value2<<endl;
	swapR(value1, value2);		// call by reference
	cout<<"After Swap Data Is(using call by reference) : "<<value1<<" "<<value2<<endl;

	// for float value

	float fvalue1 = 11.3,fvalue2=21.3;
	cout<<"Before Swap Data Is : "<<fvalue1<<" "<<fvalue2<<endl;
	swapR(fvalue1, fvalue2);		// call by reference
	cout<<"After Swap Data Is(using call by reference) : "<<fvalue1<<" "<<fvalue2<<endl;

	// for char value

	char cvalue1 = 'A',cvalue2='B';
	cout<<"Before Swap Data Is : "<<cvalue1<<" "<<cvalue2<<endl;
	swapR(cvalue1, cvalue2);		// call by reference
	cout<<"After Swap Data Is(using call by reference) : "<<cvalue1<<" "<<cvalue2<<endl;




	return 0;
}