package src;

/**
 * 汽车类继承自抽象机动车类
 */
public class Car extends AbstractVehicle {

    public String name = "car";
    private int type = 1;
    public int weight = 2500;

    public Car(String name) {
        this.name = name;
    }

    @Override
    public boolean create() {
        System.out.println("car has been produced: " + " " + this.type + " " + this.name + " " + this.weight);
        return true;
    }

    @Override
    public String getName() {
        return this.name;
    }
}