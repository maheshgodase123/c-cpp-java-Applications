// input filename from user and print size of the file

import java.lang.*;
import java.util.*;
import java.io.*;

public class program136 {

    public static void main(String[] args) {

	  try
	  {
        	Scanner sobj = new Scanner(System.in);

        	System.out.println("Please Enter File Name");
        	String Filename = sobj.nextLine();

        	File fobj = new File(Filename);

	  	if(fobj.exists())
	  	{
			long size = fobj.length();
			System.out.println("File Size Is : "+ size);
	  	}
	  	else
	  	{
			System.out.println("There Is No File");
        	}

	  }

	  catch(Exception exception)
    	  {
	   	exception.printStackTrace();
        }
    }

   
}
