#include<stdio.h>



//////////////////////////////////////////////////////
// function      : Addition
// use           : Use to add to user given no's
// date          : 13-04-2022
// author        : Mahesh Ankush Godase
//////////////////////////////////////////////////////



int Addition(int ivalue1, int ivalue2)
{

    int ivalue3 = ivalue1 + ivalue2 ;
    
    return ivalue3;
}


///////////////////////////////////////////////////////
//main function gives addition off two no's
///////////////////////////////////////////////////////


int main()
{


    int ino1 = 0;
    int ino2 = 0;
    int ino3 = 0;

    printf("Enter The First No :\n ");
    scanf("%d", &ino1);

    printf("Enter The Second No :\n ");
    scanf("%d", &ino2);
    
// calling the Addition function

    ino3 = Addition(ino1, ino2);
    printf("Addition Is : %d\n", ino3);

    return 0;
}