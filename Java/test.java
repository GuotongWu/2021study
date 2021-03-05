import java.util.*;
import top.omysycamore.*;
class Sum{
    int [] x;
    Sum(int [] tmp){
        x = tmp;
    }
    double caculator(){
        int sum = 0;
        for(int item: x)
            sum += item;
        return sum*1.0;
    }
    // static int number = 111;
    // public void f(int ... x){
    //     x[0]++;
    //     for(int item: x)
    //         System.out.print(item+" ");
    //     System.out.print("\n");
    // }
}

class Average extends Sum{
    Average(int[] tmp) {
        super(tmp);
        // TODO Auto-generated constructor stub
    }
    @Override
    double caculator(){
        int sum = 0;
        for(int item: x)
            sum += item;
        return sum*1.0/x.length;
    }
    double getSum(){
        return super.caculator();
    }
}
public class test{
    public static final double PI = 3.14; // const
    public static void main(String[] args){
        int [] sum = {0,1,3,-9,2};
        Average a = new Average(sum);
        System.out.println("ave = " + a.caculator());
        System.out.println("sum = " + a.getSum());
    }
}