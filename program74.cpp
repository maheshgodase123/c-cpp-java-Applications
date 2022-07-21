// take no from user and print its factorial

#include<iostream>
using namespace std;

class Number
{
	private:	//access specifier(by default private)
		int iNo;	// Characteristics(ENCAPSULATION AND ABSTACTION)

	public:
		// below are Behaviours

	void Accept()	//getter
	{
		cout<<"Enter the Value : "<<endl;
		cin>>this->iNo;	//we use accept(setter) method bcoz we have make iNo as private
					// so we can access iNo without accept(cannot change and print outside class)
	}	

	void Display()	//setter
	{
		cout<<"Value is : "<<this->iNo<<endl;  // we have to use this-> bcoz to access private charactiristics
	}

	int Factorial()
	{
		int iFact = 1;
		int iCnt = 0;

		for(iCnt=1; iCnt<= iNo; iCnt++)
		{
			iFact = iFact*iCnt;
		}

		return iFact;
	}
};

int main()
{
	Number nobj;
	Number nobj2;

	int iRet = 0;

	//cout<<nobj.iNo;	this will give you error bcoz iNo is private;(benifits of oop)

	nobj.Accept();
	nobj.Display();

	iRet = nobj.Factorial();  // no need to pass parameter as iNo is characteristics of our class(private)

	cout<<"Factorial Is : "<<iRet<<endl;

	// can create multiple objects and application

	nobj2.Accept();
	nobj2.Display();

	iRet = nobj2.Factorial();

	cout<<"Factorial Is : "<<iRet<<endl;

	//cout<<this->iNo<<endl; cannot access iNo bcoz private characteristics

	return 0;
}

// those variables which are importants make them private so we cannot access them outside class 