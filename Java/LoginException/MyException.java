package LoginException;

public class MyException extends Exception{
    private String message;
    public MyException(String m){
        super(m);
        message = m;
    }
}
