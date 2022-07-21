// Check the given no is even or not

#include<stdio.h>
#include<stdbool.h>

////////////////////////////////////////////////////////////////////
// function      : CheckEven
// Use           : use to check given no is even or not
// Date          : 20/04/2022
// Author        : Mahesh Ankush Godase
////////////////////////////////////////////////////////////////////


bool CheckEven(int iNo1)
{

    if((iNo1 % 2) == 0)
    {
         return true;
    }
    else
    {
         return false;
    }
}

int main()
{

    int iValue = 0;
    bool bRet = false;
  
    printf("Enter number\n");
    scanf("%d", &iValue);

    bRet = CheckEven(iValue);

    if(bRet == true)
    {
         printf("%d is even number\n", iValue);
    }
    else
    {
         printf("%d is odd number\n", iValue);
    }

    return 0;
}


////////////////////////////////////////////////////////////////////
// input - 11
// output - 11 is odd no

// input - 12
// output - 12 is even no

// input - -50
// output - -50 is even no
/////////////////////////////////////////////////////////////////////