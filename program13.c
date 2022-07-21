// Program to display 1 to 5 on screen by giving user given no
// output 1 to user given no


#include<stdio.h>

//Demonstration of ITERATION


/////////////////////////////////////////////////////////////
// function      : display
// use           : to display 1 to 5 digits
// date          : 19/04/2022
// Author        : Mahesh Ankush Godase.
/////////////////////////////////////////////////////////////

void Display(int iNo1)   // Definition

// we write voide if function is not going to return anything and we can call it

{

   if(iNo1 < 0)
   {
  
        iNo1 = -iNo1;

   }

   int iCnt = 0;
    
   for(iCnt = 1; iCnt<=iNo1; iCnt++)
   {
       printf("%d\n",iCnt);
   }
    
   
}


int main()
{
    int iUser = 0;

    printf("Enter No :- \n");
    scanf("%d", &iUser);

    Display(iUser);   //Function Call
    
    return 0;
}

///////////////////////////////////////////////////////////////////////
//output - 1 to user given value
///////////////////////////////////////////////////////////////////////