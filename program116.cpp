#include<iostream>

using namespace std;

template<class T>

T Maximum(T *Arr, int size)
{
	T max = Arr[0];

	for(int iCnt = 0; iCnt < size; iCnt++)
	{
		if(Arr[iCnt] > max)
		{
			max = Arr[iCnt];
		}

	}

	return max;

}

int main()
{
	int Brr[] = {10,20,30,40,50};
	int iret = Maximum(Brr,5);
	cout<<"Maximum No In INT : "<<iret<<endl;

	float Crr[] = {10.11,20.11,30.11,40.11,50.1100};
	float fret = Maximum(Crr,5);
	cout<<"Maximum No In float : "<<fret<<endl;

	char Drr[] = {'A','B','C','D','E','F'};
	char cret = Maximum(Drr,5);
	cout<<"Maximum No In char : "<<cret<<endl;

	
	double Err[] = {10.11,20.11,30.11,40.11,50.1110};
	double dret = Maximum(Err,5);
	cout<<"Maximum No In double : "<<dret<<endl;


	
	return 0;
}