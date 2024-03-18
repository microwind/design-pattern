package src;

/**
 * 巴士类继承自抽象机动车类
 */
public class Bus extends AbstractVehicle {

    public String name = "bus";
    private int type = 2;
    public int weight = 15000;

    public Bus(String name) {
        this.name = name;
    }

    @Override
    public boolean create() {
        System.out.println("bus has been produced: " + " " + this.type + " " + this.name + " " + this.weight);
        return true;
    }

    @Override
    public String getName() {
        return this.name;
    }
}