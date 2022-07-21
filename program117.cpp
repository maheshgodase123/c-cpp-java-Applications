#include<iostream>

using namespace std;

template<class T>

class ArrayX
{
	private:
		T *Arr;
		int Size;
	public:
		ArrayX(int);

		~ArrayX();

		void Accept();

		void Display();

		T Maximum();

};

template<class T>
ArrayX<T>::ArrayX(int value)	// compiler will know now its class of template using <T>
{
	Size = value;

	Arr = new T[Size];
}

template<class T>
ArrayX<T>::~ArrayX()
{
	delete [] Arr;
}

template<class T>
void ArrayX<T>::Accept()
{
	cout<<"Enter The Values : "<<endl;
	for(int i=0; i<Size; i++)
	{
		cin>>Arr[i];
	}
}

template<class T>
void ArrayX<T>::Display()
{
	cout<<"Values Are : "<<endl;
	for(int i=0; i<Size; i++)
	{
		cout<<Arr[i]<<" ";
	}
	cout<<endl;
}

template<class T>
T ArrayX<T>::Maximum()
{
	T max = Arr[0];

	for(int i=0; i<Size; i++)
	{
		if(Arr[i] > max)
		{
			max = Arr[i];
		}
	}

	return max;
}


int main()
{
	ArrayX <int>obj(5);	// compiler will know that we are passing integere using this<int>

	obj.Accept();
	obj.Display();

	cout<<"Maximum No is : "<<obj.Maximum()<<endl;

	ArrayX <float>obj2(5);	// compiler will know that we are passing float using this<float>

	obj2.Accept();
	obj2.Display();

	cout<<"Maximum No is : "<<obj2.Maximum()<<endl;
	return 0;
}