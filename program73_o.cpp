// take no from user and print its factorial

#include<iostream>
using namespace std;

class Number
{
	public:	//access specifier(by default private)
	int Factorial(int no)
	{
		int iFact = 1;
		int iCnt = 0;

		for(iCnt=1; iCnt<= no; iCnt++)
		{
			iFact = iFact*iCnt;
		}

		return iFact;
	}
};

int main()
{
	Number nobj;

	int iValue = 0;
	int iRet = 0;

	cout<<"Enter The Number\n";
	cin>>iValue;

	iRet = nobj.Factorial(iValue);

	cout<<"Factorial Is : "<<iRet<<endl;

	return 0;
}