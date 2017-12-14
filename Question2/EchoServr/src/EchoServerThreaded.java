import java.net.*;
import java.io.*;
import java.lang.String;
/**
 * Created by Blackbird on 12/13/2017.
 */
public class EchoServerThreaded extends Thread {
    protected Socket socket;

    public EchoServerThreaded(Socket cSocket) {
        this.socket = cSocket;
    }
@Override
    public void run(){

        try{

            BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            String line;
            StringBuffer sb = new StringBuffer();
            while((line = reader.readLine())!=null){
                int a = Integer.parseInt(line);
                char c = (char)a;
                String b;
                b =  Character.toString (c);
                sb.append(b);
            }
            System.out.println("Server " + sb.toString());


            socket.close();


        }catch (IOException ioe){
            System.err.println(ioe);
        }
    }
}

