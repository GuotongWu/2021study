package Animal_test;

public class Dog implements Animal{
    public void cry() {
        System.out.println("Wang-Wang");
    }
    public String getAnimalName(){
        return "dog";
    }
}