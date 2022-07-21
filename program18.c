// Check wheather student is passed with which class
// 0 to 34   Fail 
// 35 to 49  Pass Class
// 50 to 59  Second Class
// 60 to 69  First Class
// 70 to 100 First Class With Distinction 


#include<stdio.h>

////////////////////////////////////////////////////////////////////
// function      : Display
// Use           : Check no is divisible by 3 and 5
// Date          : 20/04/2022
// Author        : Mahesh Ankush Godase
////////////////////////////////////////////////////////////////////

void DisplayClass(float fMarks)
{
    if((fMarks >= 0.0) && (fMarks< 35.0))
    {
         printf("Your Are Fail");
    }
    else if((fMarks >= 35.0) && (fMarks< 50.0))
    {
         printf("Your Are Pass");
    }
    else if((fMarks >= 50.0) && (fMarks< 60.0))
    {
         printf("Your Are Pass With Second Class");
    }
    else if((fMarks >= 60.0) && (fMarks< 70.0))
    {
         printf("Your Are Pass With First Class ");
    }
    else if((fMarks >= 70.0) && (fMarks <= 100.0))
    {
         printf("Your Are First Class With Distinction");
    }
    else
    {
         printf("Invalid Marks!\n");
    }
}

int main()
{

    float fValue = 0.0;
    
    printf("Enter the percentage\n");
    scanf("%f", &fValue);

    DisplayClass(fValue);

    return 0;
}


////////////////////////////////////////////////////////////////////
// input - 30
// output - You are fail

// input - 35
// output - you are pass

// input - 90
// output - you are first class with distinction
/////////////////////////////////////////////////////////////////////