// input filename from user and open the file

import java.lang.*;
import java.util.*;
import java.io.*;

public class program135 {

    public static void main(String[] args) {

	  try
	  {
        	Scanner sobj = new Scanner(System.in);

        	System.out.println("Please Enter File Name");
        	String Filename = sobj.nextLine();

        	File fobj = new File(Filename);

	  	boolean bobj = fobj.createNewFile();

	  	if(bobj == true)
	  	{
			System.out.println("File Is Created");
	  	}
	  	else
	  	{
			System.out.println("File Is Already Existing!!");
        	}

	  }

	  catch(Exception exception)
    	  {
	   	exception.printStackTrace();
        }
    }

   
}
