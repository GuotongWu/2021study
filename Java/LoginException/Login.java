package LoginException;

public class Login {
    String usrname;
    String password;
    public Login(String name, String psword){
        usrname = name;
        password = psword;
    }
    public void throwException(String psword) throws MyException{
        if(!psword.equals(password))
            throw new MyException("password incorrect");
    }
    
}
