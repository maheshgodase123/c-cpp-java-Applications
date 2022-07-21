// input filename from user and reading data in the given bytes(ex - 100)

import java.lang.*;
import java.util.*;
import java.io.*;
import java.nio.charset.StandardCharsets;

public class program138 {

    public static void main(String[] args) {

	  try
	  {
        	Scanner sobj = new Scanner(System.in);

        	System.out.println("Please Enter File Name");
        	String Filename = sobj.nextLine();

        	File fobj = new File(Filename);


	  	if(fobj.exists())
	  	{
			FileInputStream fiobj = new FileInputStream(fobj);
			byte buffer[] = new byte[100];

			int ret = 0;

			while((ret = fiobj.read(buffer)) != -1)
			{
				String str1 = new String(buffer, StandardCharsets.UTF_8);
				System.out.println(str1);
			}
	  	}
	
	  	else
	  	{
			System.out.println("There Is No File");
        	}

	  }

	  catch(IOException exception)
    	  {
	   	exception.printStackTrace();
        }
    }

   
}
