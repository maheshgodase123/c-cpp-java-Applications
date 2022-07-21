// Program to display 5 times "hello" on screen


#include<stdio.h>

//Demonstration of ITERATION


/////////////////////////////////////////////////////////////
// function      : display
// use           : to display hello word using itertion
// date          : 18/04/2022
// Author        : Mahesh Ankush Godase.
/////////////////////////////////////////////////////////////



void Display()   // Definition

// we write voide if function is not going to return anything and we can call it

{
    
    int iCnt = 0;


    //1 - Initialization
    //2 - Condition
    //3 - Displacement
    //4 - Loop body


    //     1          2       3
    for(iCnt = 1; iCnt<=5 ; iCnt++)
    {

          printf("hello\n"); // 4
    }

    
   
}


int main()
{
    
    Display();   //Function Call
    
    return 0;
}
