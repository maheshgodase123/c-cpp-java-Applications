// input directory name from user and print files in directory

import java.lang.*;
import java.util.*;
import java.io.*;
import java.nio.charset.StandardCharsets;

public class program140 {

    public static void main(String[] args){

	  try
	  {
        	Scanner sobj = new Scanner(System.in);

        	System.out.println("Please Enter Directory Name");
        	String foldername = sobj.nextLine();

		File dobj = new File(foldername);

		File allfiles[] = dobj.listFiles();
		String name;

		File fobj = new File("Combine.txt");
		boolean bobj = fobj.createNewFile();
		FileOutputStream fwrite = new FileOutputStream(fobj);

		FileInputStream fread = null;
		int ret = 0;
		byte buffer[] = new byte[100];

		for(File object : allfiles)
		{
			String filename = object.getName();

			if(filename.endsWith(".txt"))
			{
				fread = new FileInputStream(object);

				while((ret = fread.read(buffer)) != -1)
				{
					fwrite.write(buffer,0,ret);
				}

			}		
		} 
        	

	  }

	  catch(Exception exception)
    	  {
	   	exception.printStackTrace();
        }
    }

   
}
