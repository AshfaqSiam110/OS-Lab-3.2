/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pkg180204110_readerwriterprb;

/**
 *
 * @author USER
 */
import java.util.concurrent.Semaphore;
import java.util.logging.Level;
import java.util.logging.Logger;

class BufferResource {
    int[] buffer = new int[1000];
    int index = 0;
    int readerCount = 0;
    boolean writerInside = false;
    
    
    
    Semaphore read = new Semaphore(4);
    Semaphore write = new Semaphore(1);
}

class Reader implements Runnable {

    BufferResource sr;

    Reader(BufferResource sr) {
        this.sr = sr;
    }

    @Override
    public void run() {
        while(true){
        if ( sr.writerInside == false) {
            try {
                sr.read.acquire();
                sr.readerCount++;
                System.out.println("\nReader "+ Thread.currentThread().getName() + " is currently reading ");
                Thread.sleep(600);
                System.out.println("\nReader "+ Thread.currentThread().getName() + " is currently leaving ");
            
                sr.readerCount--;
                sr.read.release();
                Thread.sleep(2450);

            } catch (InterruptedException ex) {
                Logger.getLogger(Reader.class.getName()).log(Level.SEVERE, null, ex);
            }
        }

    }}
}

class Writer implements Runnable {

    BufferResource sr;

    Writer(BufferResource sr) {
        this.sr = sr;
    }

    @Override
    public void run() {
        
        try {
            
            while (true) {
                Thread.sleep(600);
                System.out.print("");
                if( sr.readerCount == 0){
                    
                    sr.write.acquire();
                    sr.writerInside = true;
                    sr.buffer[sr.index] = sr.index+1;
                    sr.index++;
                    System.out.println("\nWriter "+Thread.currentThread().getName() + " is currently writing ");
                    System.out.println("Data in buffer : ");
                    for(int i=0;i<sr.index;i+=2){
                       
                        System.out.print(sr.buffer[i]+" ");
                    }
                    Thread.sleep(200);
                    System.out.println("\nWriter "+Thread.currentThread().getName() + " is currently leaving ");
                    sr.writerInside = false;
                    sr.write.release();
                                      
                }
            }
        } catch (InterruptedException ex) {
            Logger.getLogger(Writer.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}

public class Main {

    public static void main(String args[]) {
        BufferResource br = new BufferResource ();
       

        Reader r1 = new Reader(br);
        Reader r2 = new Reader(br);
        Reader r3 = new Reader(br);
        Reader r4 = new Reader(br);
        
        Writer r5 = new Writer(br);
        Writer r6 = new Writer(br);

        new Thread(r1, "Siam").start();
        new Thread(r2, "Rudra").start();
        new Thread(r3, "Abir").start();
        new Thread(r4, "Jishan").start();
        
        new Thread(r5, "Siam").start();
        new Thread(r6, "Rudra").start();
    }
}


