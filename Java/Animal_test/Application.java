package Animal_test;

public class Application {
    public static void main(String[] args) {
        Simulator simulator = new Simulator();
        simulator.playsound(new Dog());
        simulator.playsound(new Cat());   
    }
}
