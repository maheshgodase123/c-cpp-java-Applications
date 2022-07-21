#include<iostream>

using namespace std;

template<class T>

void Display(T *Arr, int size)	// no need to make size t bcoz size will be in int only
{
	for(int iCnt = 0; iCnt < size; iCnt++)
	{
		cout<<Arr[iCnt]<<endl;

	}

}

int main()
{
	int Brr[] = {10,20,30,40,50};
	Display(Brr,5);

	float Crr[] = {10.11,20.11,30.11,40.11,50.11};
	Display(Crr,5);

	
	return 0;
}