import java.util.Scanner;

class CowFarm {
    static String cname;
    Cow cow;

    CowFarm(int a, int b, int c, String s) {
        cow = new Cow(a, b, c);
        cname = s;
    }

    void farmSpeak(int[] a) {
        for (int item : a) {
            if (item == 0)
                try {
                    throw new Div0Exception();
                } catch (Div0Exception e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
            else
                item = 10 / item;
        }
    }
    class Cow{
        int height;
        int weight;
        int price;
        Cow(int a, int b, int c){
            height = a;
            weight = b;
            price = c;
        }
        void speak(){
            System.out.println("height = " + height + "\nweight = " + weight + "\nprice = " + price);
        }
    }
}

class Div0Exception extends Exception{
    String message;
    public Div0Exception(){
        message = "Error: divide 0 can not be solved";
    }
    public String warnMess(){
        return message;
    }
}
public class test
{
    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        int sum = 0;
        int cnt = 0;
        while(reader.hasNextInt()){
            int x = reader.nextInt();
            assert x<=100 && x>=0: "The grade is not correct";
            sum += x;
            cnt++;
            if(cnt==5)
                break;
        }
        System.out.println("sum = " + sum + "  ave = " + sum*1.0/cnt);
    }
}