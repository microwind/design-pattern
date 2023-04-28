package src;

// 指挥调度类，负责利用建造者建造产品，隔离需求
public class Director {

  // 建造phone1
  public void buildIPhone(Builder builder) {
    builder.reset();
    Integer[] screen = { 120, 500 };
    builder.setName("iPhone");
    builder.setScreen(screen);
    builder.setGPU(100);
  }

  // 建造phone2
  public void buildHuaweiPhone(Builder builder) {
    builder.reset();
    Integer[] screen = { 130, 600 };
    // 也可以链式调用
    builder.setName("HuaweiPhone")
    .setScreen(screen)
    .setGPU(102);
  }

  // 建造phone3
  public void buildMiPhone(Builder builder) {
    builder.reset();
    Integer[] screen = { 120, 650 };
    builder.setName("MiPhone");
    builder.setScreen(screen);
    builder.setGPU(103);
  }

}
