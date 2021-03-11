package Animal_test;

public class Simulator{
    public void playsound(Animal animal){
        animal.cry();
        System.out.println("The name is " + animal.getAnimalName());
    }
}
