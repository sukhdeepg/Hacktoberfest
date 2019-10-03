package ProducerConsumer;

import static java.lang.Thread.sleep;

class ProCon {

    private static int value = 0;
    private static boolean flag;
    private static ProCon object = new ProCon();

    synchronized void produce() throws Exception{
        while (true) {
            if (flag) {
                wait();
            }

            System.out.println("\nProduced = " + value);
            flag = true;

            notify();
            //sleep(5000);
        }
    }

    synchronized void consume() throws Exception{
        while (true) {
            if (!flag) {
                wait();
            }

            System.out.println("\nConsumed = " + value);
            ++value;
            flag = false;

            notify();
            sleep(2000);
        }
    }

    public static void main(String[] args){
        consumer c = new consumer();
        producer p = new producer();
        producer p2 = new producer();
        p2.start();
        p.start();
        c.start();
    }

    static ProCon getObject(){
        return object;
    }
}

class producer extends Thread{

    private ProCon pro;

    producer(){
        pro = ProCon.getObject();
    }

    public void run(){
        try {
            pro.produce();
            //sleep(5000);
        }catch (Exception ex){
            System.out.println(ex.getMessage());
        }
    }
}

class consumer extends Thread{

    private ProCon con;

    consumer(){
        con = ProCon.getObject();
    }

    public void run(){
        try {
            con.consume();
            //sleep(5000);
        }catch (Exception ex){
            System.out.println(ex.getMessage());
        }
    }
}