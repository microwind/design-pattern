# 【建造者设计模式详解】C/Java/JS/Go/Python/TS不同语言实现

# 简介
建造者模式（Builder Pattern），也叫生成器模式，属于创建型模式。它使用多个简单的对象一步一步构建成一个复杂的对象。它允许你使用相同的创建代码生成不同类型和形式的对象。

当你希望使用代码创建不同形式的产品 （例如各种商品和订单） 时， 一些基本部件不会变，而其组合经常变化的时候，就可以考虑建造者模式。

# 作用
1. 当需要创建复杂对象的时候，由各个部分的子对象来逐步构建，以适应复杂多变的情况。
2. 具体的建造者类之间是相互独立的，这有利于系统的扩展。
3. 将变与不变分离开。主管类隐藏了产品构造细节， 客户端只需要将一个生成器与主管类关联，就能从生成器处构造对象。

# 实现步骤
1. 定义主管类，可以制造所有形式的产品。
2. 在基本生成器接口中声明创建产品的步骤。
3. 为每个形式的产品创建具体生成器类，并实现其构造步骤。
4. 客户端同时创建生成器和主管类，所有产品都遵循相同的接口，构造结果通过主管类获取。

# UML
<img src="../docs/uml/builder-pattern.png">


# 代码

## 创建建造者接口
```java
// Builder.java 建造者接口，定义基本建造方法
public interface Builder {
  public void reset();
  public void setName(String name);
  public void setScreen(Integer[] screen);
  public void setGPU(Integer no); 
}

```

## 具体建造者类，可以多个
```java
// ManualBuilder.java 使用手册建造者类也实现了建造者接口
public class ManualBuilder implements Builder {
  private Manual manual;

  public void reset() {
    this.manual = new Manual();
  }

  public void setName(String name) {
    this.manual.setName(name);
  }

  public void setScreen(Integer[] screen) {
    this.manual.setScreen(screen);
  }

  public void setGPU(Integer no) {
    this.manual.setGpuType(no);
  }

  public Manual getProduct() {
    return this.manual;
  }
}
```

```java
// PhoneBuilder.java 手机建造者实现了建造者接口
public class PhoneBuilder implements Builder {
  private Phone phone;

  public void reset() {
    this.phone = new Phone();
  }

  public void setName(String name) {
    this.phone.setName(name);
  }

  public void setScreen(Integer[] screen) {
    this.phone.setScreen(screen);
  }

  public void setGPU(Integer no) {
    this.phone.setGpuType(no);
  }

  public Phone getProduct() {
    return this.phone;
  }
}
```

## 定义具体产品类，不同建造者建造不同产品
```java
// Manual.java 手册产品类
public class Manual {
  private String name = "PhoneManualName";
  private Integer[] screen = { 0, 0 };
  private Integer gpuType = 0;
  private Integer pages = 0;

  public void setName(String name) {
    this.name = name;
  }

  public String getName() {
    return this.name;
  }

  public void setScreen(Integer[] screen) {
    this.screen = screen;
  }

  public Integer[] getScreen() {
    return this.screen;
  }
  ......

}
```

```java
// Phone.java 手机产品类
public class Phone {
  private String name = "PhoneName";
  private Integer[] screen = { 0, 0 };
  private Integer gpuType = 0;

  public void setName(String name) {
    this.name = name;
  }

  public String getName() {
    return this.name;
  }

  public void setScreen(Integer[] screen) {
    this.screen = screen;
  }

  public Integer[] getScreen() {
    return this.screen;
  }
  ......

}
```

## 指挥调度类
```java
// Director.java 指挥调度类，负责利用建造者建造产品，隔离需求与功能
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
    builder.setName("HuaweiPhone");
    builder.setScreen(screen);
    builder.setGPU(102);
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
```

## 测试调用
```java
    /**
     * 建造者模式是使用多个简单的对象一步一步构建出一个复杂的对象来。
     * 分为主管类和建造这类，主管类负责具体指挥调度，建造负责具体实施。
     * 主管类通过一步一步调用各种建造者实现复杂对象。
     */

    // 声明指挥者
    Director director = new Director();
    // 创建手机
    PhoneBuilder phoneBuilder = new PhoneBuilder();
    director.buildMiPhone(phoneBuilder);
    Phone miPhone = phoneBuilder.getProduct();
    System.out.println("miPhone:" + miPhone.getName() + " | " + miPhone.getGpuType().toString());
    // 创建手册
    ManualBuilder manualBuilder = new ManualBuilder();
    director.buildMiPhone(manualBuilder);
    Manual manual = manualBuilder.getProduct();
    System.out.println("manual:" + manual.getName() + " | " + manual.getGpuType().toString());

```

## 更多语言版本
不同语言设计模式源码：[https://github.com/microwind/design-pattern](https://github.com/microwind/design-pattern)