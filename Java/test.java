public class test{
    public static final double PI = 3.14; // const
    public static void main(String[] args){
        System.out.println("PI = " + PI);
        System.out.print("Hello World!\n");
        int[] numbers = {12, 3, 2, 454, 3, 43, 4, 34, 54, 45};
        for(int i=0; i<numbers.length; ++i)
            System.out.printf("%d ", numbers[i]);
        System.out.println(' ');
        // for-each方式遍历
        for(int item : numbers)
            System.out.printf("%d ", item);
         
    }
}