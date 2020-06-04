import java.io.*;
import java.net.*;

public class UppercaseClient {
    public static void main(String[] args) throws IOException {
        if (args.length != 2) {
            System.out.println(
               "Usage: java UppercaseClient <server> <portNum>");
            System.exit(1);
        }
        String serverName = args[0];
        int portNum = Integer.parseInt(args[1]);

	Socket requestSocket = new Socket(serverName, portNum);

	BufferedReader consoleReader
	    = new BufferedReader(new InputStreamReader(System.in));

	BufferedReader requestReader
	    = new BufferedReader(
		  new InputStreamReader(requestSocket.getInputStream()));
	Writer responseWriter
	    = new OutputStreamWriter(requestSocket.getOutputStream());

	while(true) {
	    System.out.println("Please type a string to convert");
	    
	    String requestString = consoleReader.readLine();
	    responseWriter.write(requestString + "\n");
	    responseWriter.flush();
	    System.out.println("Requested: " + requestString);
	    System.out.println("Response: " + requestReader.readLine());
			       
	}
    }
}
