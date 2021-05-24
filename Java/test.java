interface aaa{
    void speak();
    void say();
}

abstract class hello implements aaa{
    public abstract void speak();
    // abstract void say();
}

interface dd{}
public class test{
    static void te(){
        hello testhello = new hello(){
            public void speak(){
                System.out.println("hello");
            }
            public void say(){}
        };
        testhello.speak();

        dd DD = new dd(){

            static float p = 2.5f;
        };
    }
    public static void main(String[] args) {
        te();
    }
}