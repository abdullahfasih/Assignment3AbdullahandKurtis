package com.company;
import java.net.*;
import java.io.*;


public class Main{

    public static void main(String[] args) {


        try {
            Socket server = new Socket("localhost", 4000 );
            InputStreamReader isr = new InputStreamReader(System.in);
            System.out.println("please enter your data");



            PrintWriter pout = new PrintWriter(server.getOutputStream(), true);

           int chr;


            while((chr = isr.read())!= 10){

               pout.println(chr);
            }



            server.close();

        } catch (IOException ioe) {
            System.out.println(ioe);
        }

    }
}
