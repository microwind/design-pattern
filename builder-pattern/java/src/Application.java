package src;

// 客户调用类，将建造过程再封装
// 也可以单独给外部调用，而无需再次封装
public class Application {
  public static void makeIPhone() {
    Director director = new Director();
    // 创建手机
    PhoneBuilder phoneBuilder = new PhoneBuilder();
    director.buildIPhone(phoneBuilder);
    Phone iPhone = phoneBuilder.getProduct();
    System.out.println("iPhone:" + iPhone.getName() + " | " + iPhone.toString());

    // 创建手册
    ManualBuilder manualBuilder = new ManualBuilder();
    director.buildIPhone(manualBuilder);
    Manual manual = manualBuilder.getProduct();
    System.out.println("manual:" + manual.getName() + " | " + manual.toString());

  }

  public static void makeHuaweiPhone() {
    Director director = new Director();

    // 创建手机
    PhoneBuilder phoneBuilder = new PhoneBuilder();
    director.buildHuaweiPhone(phoneBuilder);
    Phone huaweiPhone = phoneBuilder.getProduct();
    System.out.println("huaweiPhone:" + huaweiPhone.getName() + " | " +  huaweiPhone.toString());

    // 创建手册
    ManualBuilder manualBuilder = new ManualBuilder();
    director.buildHuaweiPhone(manualBuilder);
    Manual manual = manualBuilder.getProduct();
    System.out.println("manual:" + manual.getName() + " | " + manual.toString());

  }

}
