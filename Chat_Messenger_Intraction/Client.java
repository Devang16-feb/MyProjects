import java.net.*;
import java.io.*;

public class Client 
{
    public static void main(String[] args) throws Exception
    {
        System.out.println("Client application is running...");


        Socket sobj = new Socket("localhost",2100);
        System.out.println("Client gets succesfully connected...");
        PrintStream ps = new PrintStream(sobj.getOutputStream());
        BufferedReader br1 = new BufferedReader(new InputStreamReader(sobj.getInputStream()));
        BufferedReader br2 = new BufferedReader(new InputStreamReader(System.in));
        String str1, str2;

        System.out.println("marvellous messanger started...");
        while (!(str1 = br2.readLine()).equals("End"))
        {
            ps.println(str1);
            str2 = br1.readLine();
            System.out.println("Enter Message to server :");
            System.out.println("server says :"+str2);  
        }
        System.out.println("Thank you for using Marvellous Massenger..");
    }
    
}
