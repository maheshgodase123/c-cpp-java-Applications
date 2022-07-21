// Check the given no is divisible by 3 and 5

#include<stdio.h>
#include<stdbool.h>

////////////////////////////////////////////////////////////////////
// function      : CheckDivisible
// Use           : Check no is divisible by 3 and 5
// Date          : 20/04/2022
// Author        : Mahesh Ankush Godase
////////////////////////////////////////////////////////////////////


bool CheckDivisible(int iNo1)
{

    if((iNo1 % 3) == 0 && (iNo1 % 5)==0)
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

    bRet = CheckDivisible(iValue);

    if(bRet == true)
    {
         printf("%d is divisible by 3 and 5\n", iValue);
    }
    else
    {
         printf("%d is not divisible by 3 and 5\n", iValue);
    }

    return 0;
}


////////////////////////////////////////////////////////////////////
// input - 30
// output - 30 is divisible by 3 and 5

// input - 15
// output - 15 is divisible by 3 and 5

// input - 9
// output - 9 is not divisible by 3 and 5
/////////////////////////////////////////////////////////////////////