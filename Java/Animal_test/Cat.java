package Animal_test;

public class Cat implements Animal {
    public void cry(){
        System.out.println("Miao-Miao");
    }
    public String getAnimalName(){
        return "cat";
    }
}
