package src;

/**
 * Light实现类，实现Light控制接口的全部方法
 */
public class Light implements LightController {
    @Override
    public void turnOn() {
        // 执行灯光打开操作
        System.out.println("Turn on Light");
    }

    @Override
    public void turnOff() {
        // 执行灯光关闭操作
        System.out.println("Turn off Light");
    }

    @Override
    public void changeLightColor(String color) {
        // 执行灯光颜色切换
        System.out.println("Change Light color to " + color);
    }
}