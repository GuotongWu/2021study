package LoginException;

public class Main {
    public static void main(String[] args) {
        Login log = new Login("hhh", "123");
        try{
            log.isCorrect("1234");
        }catch(MyException me){
            System.out.println("Log failed: " + me.getMessage());
        }
    }
}