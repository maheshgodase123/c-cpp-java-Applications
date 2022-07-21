// Program to display user given times "hello" on screen


#include<stdio.h>

//Demonstration of ITERATION


/////////////////////////////////////////////////////////////
// function      : display
// use           : to display hello word using itertion
// date          : 18/04/2022
// Author        : Mahesh Ankush Godase.
/////////////////////////////////////////////////////////////



void Display(int iNo)   // Definition

// we write voide if function is not going to return anything and we can call it

{

    //1 - Initialization
    //2 - Condition
    //3 - Displacement
    //4 - Loop body


    if (iNo < 0) // Filter And Updator
    {
       iNo = -iNo;
    }


    int iCnt = 0;

    //     1          2       3
    for(iCnt = 1 ; iCnt<= iNo ; iCnt++)
    {

          printf("hello\n"); // 4
    }

    
   
}


int main()
{
    int iCnt = 0;

    printf("Enter How Many Times You Want To Print : \n");
    scanf("%d", &iCnt);

    Display(iCnt);   //Function Call
    
    return 0;
}

///////////////////////////////////////////////////////////////////
// INPUT - 5
// OUTPUT - it will print 5 times hello
///////////////////////////////////////////////////////////////////