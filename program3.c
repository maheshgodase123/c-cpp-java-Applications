#include<stdio.h>


/////////////////////////////////////////////////
// write a program to add two no's given by user
/////////////////////////////////////////////////


int main()
{

    int ino1 = 0;
    int ino2 = 0;
    int ino3 = 0;

    printf("Enter The First No :\n");
    scanf("%d", &ino1);

    printf("Enter The Second No :\n");
    scanf("%d", &ino2);

    ino3 = ino1 + ino2;
    printf("Addition Is: %d\n", ino3);

    return 0;
}

