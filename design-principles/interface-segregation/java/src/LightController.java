package src;

/**
 * Light控制接口，包括TV需要的控制方法，供Light具体对象实现
 * 每个具体控制对象有其自身的接口，不跟其他对象混在一起
 */
public interface LightController extends DeviceController {
    public void changeLightColor(String color);
}