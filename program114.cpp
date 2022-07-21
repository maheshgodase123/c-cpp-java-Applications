#include<iostream>

using namespace std;

template <class T>

T Addition(T no1, T no2)
{
	T Ans;
	Ans = no1 + no2;

	return Ans;
}

int main()
{
	// for int values
	int value1 = 11,value2 = 21;
	int ret = 0;

	ret = Addition(value1, value2);

	cout<<"Addition Is : "<<ret<<endl;

	// for float
	float fvalue1 = 11.5,fvalue2 = 21.5;
	float fret = 0.0;

	fret = Addition(fvalue1, fvalue2);

	cout<<"Addition Is : "<<fret<<endl;

	return 0;
}