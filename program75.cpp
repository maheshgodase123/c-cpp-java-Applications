#include<iostream>
using namespace std;

class  ArrayX
{
	private:
		int *Arr;
		int iSize;
		
	public:
		ArrayX(int iValue)	// PARAMETERIZE CONSTRUCTOR
		{
			this->iSize = iValue;
			Arr = new int[iSize];	// Allocate Resource
		}

		~ArrayX()			// Destructor(sign - tilda)
		{
			delete []Arr;	// Deallocate the resources([] is also treated as pointer(*))
		}

		void Accept()  // Accept(ArrayX *100)
		{
			int iCnt = 0;
			cout<<"Enter The Elements"<<endl;
			for(iCnt=0; iCnt < iSize; iCnt++)
			{
				cin>>Arr[iCnt];
			}
		}

		void Display()
		{
			int iCnt = 0;

			cout<<"Elements of array are"<<endl;
			for(iCnt = 0; iCnt < iSize; iCnt++)
			{
				cout<<Arr[iCnt]<<endl;
			}
		}

		int Summation()
		{
			int iSum = 0;
			int iCnt = 0;

			for(iCnt = 0; iCnt < iSize; iCnt++)
			{
				iSum = iSum + Arr[iCnt];
			}

			return iSum;
		}

};

int main()
{
	int iRet = 0;

	ArrayX obj1(5);

	obj1.Accept();	// for input   internally - Accept(obj1)   Accept(100)
	obj1.Display();	// for output  internally - Display(obj1)  Display(100)

	iRet = obj1.Summation();

	cout<<"Addition Is : "<<iRet<<endl;

	return 0;
}