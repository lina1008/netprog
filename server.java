import java.net.*; 
import java.io.*; 


public class server 
{
public static void main(String[] args) throws IOException
{
			ServerSocket server = new ServerSocket( 17800); 
			Socket socket = server.accept ();
			
			
			System.out.println ("Connected");
			
			InputStreamReader in = new InputStreamReader(socket.getInputStream());
			BufferedReader put = new BufferedReader (in);
			
			
			 PrintWriter out= new PrintWriter(socket.getOutputStream());
      
             out.println ("What's up client.");
			 out.flush();
			 
			 String str = put.readLine();
			 System.out.println("Client");
			 System.out.println (str);

} 
}
  
  
