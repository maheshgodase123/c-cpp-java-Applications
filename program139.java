// input filename from user and write the  data of given bytes(ex - 100)

import java.lang.*;
import java.util.*;
import java.io.*;
import java.nio.charset.StandardCharsets;

public class program139 {

    public static void main(String[] args) {

	  try
	  {
        	Scanner sobj = new Scanner(System.in);

        	System.out.println("Please Enter File Name");
        	String Filename = sobj.nextLine();

        	File fobj = new File(Filename);

		System.out.println("Enter new file name to create");
		String newfile = sobj.nextLine();

		File fobjnew = new File(newfile);
		boolean bobj1 = fobjnew.createNewFile();
		
	  	if(fobj.exists())
	  	{
			FileInputStream fiobj = new FileInputStream(fobj);
			FileOutputStream foobj = new FileOutputStream(fobjnew);

			byte buffer[] = new byte[100];

			int ret = 0, sum = 0;

			while((ret = fiobj.read(buffer)) != -1)
			{
				//sum = sum + ret;	// kity read krtoy te calculate krtoy

				foobj.write(buffer,0,ret);	// size nahi dili kity karaychay trr last la garbage yetiye(mnje last la 100-40 trr rahilelya 60 mdhe)
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
