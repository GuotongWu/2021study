import java.util.*;
import top.omysycamore.*;
class A{
    int x = 0;
    static int number = 111;
    public void f(int ... x){
        x[0]++;
        for(int item: x)
            System.out.print(item+" ");
        System.out.print("\n");
    }
}

public class test{
    public static final double PI = 3.14; // const
    public static void main(String[] args){
        int [] sum = {0,1,3,-9,2};
        hello h = new hello();
        h.max(3,2);
    }
}