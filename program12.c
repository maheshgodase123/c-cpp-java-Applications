// Program to display 1 to 5 on screen
// output 1 2 3 4 5


#include<stdio.h>

//Demonstration of ITERATION


/////////////////////////////////////////////////////////////
// function      : display
// use           : to display 1 to 5 digits
// date          : 19/04/2022
// Author        : Mahesh Ankush Godase.
/////////////////////////////////////////////////////////////

void Display()   // Definition

// we write voide if function is not going to return anything and we can call it

{
   int iCnt = 0;
    
   for(iCnt = 1; iCnt<=5; iCnt++)
   {
       printf("%d\n",iCnt);
   }
    
   
}


int main()
{
    
    Display();   //Function Call
    
    return 0;
}

///////////////////////////////////////////////////////////////////////
//output - 1 2 3 4 5
///////////////////////////////////////////////////////////////////////