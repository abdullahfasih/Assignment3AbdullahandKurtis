
import java.net.*;
import java.io.*;
import java.lang.String;

public class ServerThreaded {

    public static void main(String[] args) {
        Socket socket = null;
        ServerSocket sSocket = null;

        try {
            sSocket = new ServerSocket(4000);
        }catch (IOException e){
            e.printStackTrace();
        }

        while(true){
            try{
                socket = sSocket.accept();
//                System.out.println("Client connected.");
            } catch(IOException e){
                System.out.println("error" + e);
            }
            new EchoServerThreaded(socket).start();
        }
    }


}
