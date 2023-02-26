/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
import java.io.File;
public class Main
{
	public static void main(String[] args) {
		      //here the usb drive names are named as E,F,G,H in the system
      String[] drive_name = new String[]{ "E", "F", "G", "H", "I" ,"J","K", "L","M", "N"};
      //here we initialize an array for the usb that is to be inserted
      File[] usb = new File[drive_name.length];
      //if the usb is detected then it is assigned True else False
      boolean[] usb_detected = new boolean[drive_name.length];
 
      // in below loop we append :/ to the drive names because E:/ D:/  
      //and then the corresponding drive is searched with the help of canRead() method
       
 
    for ( int i = 0; i < drive_name.length; ++i )
    {
         usb[i] = new File(drive_name[i]+":/");
         //This method determines whether the program can read the file denoted by the mentioned path name
         usb_detected[i] = usb[i].canRead();
    }
 
    System.out.println("Insert USB");

    detect(usb,drive_name,usb_detected);
	}
	
    public static void detect(File[] usb,String[] drive_name,boolean[] usb_detected)
    {
        while(true)
    {
        //the following loop is iterated to find the usb inserted
        for ( int i = 0; i < drive_name.length; ++i )
        {
            boolean if_detected;
            if_detected = usb[i].canRead();

            if ( if_detected != usb_detected[i] )
                {
                    if ( if_detected )
                    System.out.println("USB "+drive_name[i]+" detected ");
 
                    usb_detected[i] = if_detected;
                }
 
        }
 
    }
}
}
