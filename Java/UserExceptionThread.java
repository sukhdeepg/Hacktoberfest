public class UserExceptionThread implements Runnable {

    private Thread t;

    private UserExceptionThread(String name){
        t = new Thread(this,name);
    }

    @Override
    public void run() {
        try {
            if (t.getName().equals("One")) {
                throw new UserException("One as a name is not allowed");
            }
            System.out.println(t.getName());
        }catch (Exception ex){
            System.out.println(ex.getMessage());
        }
    }

    public static void main(String[] args){
        UserExceptionThread u1 = new UserExceptionThread("One");
        UserExceptionThread u2 = new UserExceptionThread("Two");
        UserExceptionThread u3 = new UserExceptionThread("Three");
        UserExceptionThread u4 = new UserExceptionThread("Four");

        u1.t.start();
        u2.t.start();
        u3.t.start();
        u4.t.start();
    }
}

class UserException extends Exception{

    UserException(String s){
        super(s);
    }

    @Override
    public String toString() {
        return super.toString();
    }
}