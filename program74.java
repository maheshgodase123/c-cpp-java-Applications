import java.lang.*;
import java.util.*; 	// for input

class Number
{
	private int iNo;	//java access specifier

	// in java we have write(public/private) in front of variable every time

	public void Accept()
	{
		Scanner sobj = new Scanner(System.in);  // here we have to create variable for input
		System.out.println("Enter number : ");
		this.iNo = sobj.nextInt();	// -> is same as . in java
	}
	
	public void Display()
	{
		System.out.println("Value is : "+this.iNo);
	}

	public int Factorial()
	{
		int iFact = 1;
		int iCnt = 0;

		for(iCnt=1; iCnt<= iNo; iCnt++)
		{
			iFact = iFact*iCnt;
		}

		return iFact;	
	}

	
}

class program74
{
	public static void main(String b[])
	{
		int iRet = 0;
		Number nobj = new Number();  //obj is created

		nobj.Accept();
		nobj.Display();

		iRet = nobj.Factorial();
		System.out.println("Factorial is : "+ iRet);
	}
}