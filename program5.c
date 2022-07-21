#include<stdio.h>

int Addition(int, int);  // here we initialize func from library5.c file


//////////////////////////////////////////
// fun is used to add 2 user given no's
//////////////////////////////////////////


int main()
{


    int ino1 = 0;
    int ino2 = 0;
    int ino3 = 0;

    printf("Enter The First No : /n");
    scanf("%d", &ino1);

    printf("Enter The Second No : /n");
    scanf("%d", &ino2);
    
// calling the Addition function

    ino3 = Addition(ino1, ino2);
    printf("Addition Is : %d\n", ino3);

    return 0;
}