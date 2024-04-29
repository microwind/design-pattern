## 代码结构
```shell
- src
  - AbstractFactory.java # 抽象工厂类，定义工厂概念，被具体的工厂所继承
  - ShopFactory.java # 具体工厂类之一，负责Shop生产，继承抽象工厂
  - VehicleFactory.java # 具体工厂类之一，负责Vehichle生产，继承抽象工厂
  - FactoryCreator.java # 工厂创建类，根据产品类别创建不同的工厂
  + shop # Shop类产品文件夹
    - Shop.java # Shop接口
    - AgencyShop.ajva # Shop具体实现之一
    - DirectSale.java # Shop具体实现之一
    - SupermarketShop.java # Shop具体实现之一
  + vehicle # Vehicle类产品文件夹
    - Vehicle.java # Vehicle接口
    - Bus.java # Vehicle具体实现之一
    - Car.java # Vehicle具体实现之一
    - Motorcycle.java # Vehicle具体实现之一
    - Van # Vehicle具体实现之一
    - VehicleType.java # Vehicle的类型
```

## 测试验证

```shell
$ cd ./abstract-factory/java
$ javac test/Test.java
$ java test/Test
```
