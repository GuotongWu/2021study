public class Rational {
    int numerator = 1; // 分子
    int denominator = 1; // 分母
    void setNumerator(int x){
        int c = f(Math.abs(denominator), x);
        numerator = x/c;
        denominator /= c;
        if(numerator<0 && denominator<0){
            numerator *= -1;
            denominator *= -1;
        }
    }
    void setDenominator(int x){
        int c = f(Math.abs(numerator), x);
        numerator /= c;
        denominator = x/c;
        if(numerator<0 && denominator<0){
            numerator *= -1;
            denominator *= -1;
        }
    }
    Rational mul(Rational a){
        numerator *= a.numerator;
        setDenominator(denominator * a.denominator);
        return this;
    }
    int f(int a, int b){
        int tmp;
        if(a >= b){
            while(b > 0){
                tmp = a % b;
                a = b;
                b = tmp;
            }
            return a;
        }else{
            while(a > 0){
                tmp = b % a;
                b = a;
                a = tmp;
            }
            return b;
        }
        // System.out.println("max: " + a);
        // return a;
    }
    void printRational(){
        System.out.println(numerator + "/" + denominator);
    }
    public static void main(String [] args)
    {
        Rational r = new Rational();
        r.setNumerator(2);
        r.setDenominator(3);
        r.printRational();
        Rational r1 = new Rational();
        r1.setNumerator(3);
        r1.setDenominator(4);
        r1.printRational();
        Rational result = r.mul(r1);
        result.printRational();
    }
}
