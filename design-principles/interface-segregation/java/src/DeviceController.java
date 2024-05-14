package src;

/**
 * 电器设备的基础控制接口，把一些基础方法提取出来【可选】
 * 有时候会有一些公共的接口方法，有三种实现方式。
 * 1. 接口继承，子接口继承父接口。适用接口存在强关系。
 * 2. 让具体类同时实现多个接口，既实现具体接口，也实现基础接口。适用接口存在弱关系。
 * 3. 在每个具体接口类里面分别增加上基础方法。适用于接口独立，无关系。
 */
public interface DeviceController {
    public void turnOn();
    public void turnOff();
}