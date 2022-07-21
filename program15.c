// Program to display summation of user given no


#include<stdio.h>

//Demonstration of ITERATION


/////////////////////////////////////////////////////////////
// function      : display
// use           : to display 1 to user given digit
// date          : 19/04/2022
// Author        : Mahesh Ankush Godase.
/////////////////////////////////////////////////////////////

int Summation(int iNo1)   // Definition

// we write voide if function is not going to return anything and we can call it

{

   if(iNo1 < 0)
   {
  
        iNo1 = -iNo1;

   }

   int iCnt = 1;
   
   int iSum = 0;
    
   for(iCnt = 1; iCnt<=iNo1; iCnt++)
   {
       iSum = iSum + iCnt;
   }


   /*
   while(iCnt <= iNo1)
   {
       printf("%d\n",iCnt);
       iCnt++;
   }
   */
    
   return iSum;
}


int main()
{
    int iUser = 0;
    int iReturn = 0;

    printf("Enter No :- \n");
    scanf("%d", &iUser);

    iReturn = Summation(iUser);

    printf("Summation Is: %d\n", iReturn);  //Function call in printf
    return 0;
}

///////////////////////////////////////////////////////////////////////
//input - 5
//output - 15

//input - 4
//output - 10
///////////////////////////////////////////////////////////////////////