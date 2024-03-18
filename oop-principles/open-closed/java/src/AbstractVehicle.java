package src;

/**
 * 车辆抽象类或者是接口，用于具体对象继承或实现，便于统一约束和扩展
 */
public abstract class AbstractVehicle {
    public String name;
    public int type;
    public int weight;
    protected abstract boolean create();
    public abstract String getName();
}