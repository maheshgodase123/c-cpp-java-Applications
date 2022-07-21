
int Addition(int ivalue1, int ivalue2)
{


    //////////////////////////////////////////////////////////////
    // applyinng if statments for converting negative to positive
    // in industry there is "UPDATOR" terminology for if statement
    //////////////////////////////////////////////////////////////


    if(ivalue1 < 0)
    {
         ivalue1 = -ivalue1;
    }
    
    if(ivalue2 < 0)
    {
         ivalue2 = -ivalue2;
    }

    int ivalue3 = ivalue1 + ivalue2 ;
    
    return ivalue3;
}