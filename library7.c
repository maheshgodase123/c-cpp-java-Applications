#include "header7.h"


/////////////////////////////////////////////////////////////////////
//
//  Function Name:  Addition
//  Description :      Used to perform addition of 2 numbers
//  Input :              Integer, Integer
//  Output :            Integer
//  Date :               12/04/2022
//  Author :            Piyush Manohar Khairnar
//
/////////////////////////////////////////////////////////////////////


int Addition(int ivalue1, int ivalue2)
{


    //////////////////////////////////////////////////////////////
    // applyinng if statments for converting negative to positive
    //////////////////////////////////////////////////////////////


    if(ivalue1 < 0)
    {
         ivalue1 = ivalue1;
    }
    
    if(ivalue2 < 0)
    {
         ivalue2 = -ivalue2;
    }

    int ivalue3 = ivalue1 + ivalue2 ;
    
    return ivalue3;
}