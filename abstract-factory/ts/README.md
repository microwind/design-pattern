## 代码结构
```shell
- src
  - AbstractFactory.ts # 抽象工厂基类，定义工厂概念，被具体的工厂所继承
  - ShopFactory.ts # 具体工厂类之一，负责Shop生产，继承抽象工厂
  - VehicleFactory.ts # 具体工厂类之一，负责Vehichle生产，继承抽象工厂
  - FactoryCreator.ts # 工厂创建类，根据产品类别创建不同的工厂
  + shop # Shop类产品文件夹
    - Shop.ts # Shop基类
    - AgencyShop.ajva # Shop具体实现之一
    - DirectSale.ts # Shop具体实现之一
    - SupermarketShop.ts # Shop具体实现之一
  + vehicle # Vehicle类产品文件夹
    - Vehicle.ts # Vehicle基类
    - Bus.ts # Vehicle具体实现之一
    - Car.ts # Vehicle具体实现之一
    - Motorcycle.ts # Vehicle具体实现之一
    - Van # Vehicle具体实现之一
```

## 测试验证

```shell
$ cd ./abstract-factory/ts
$ tsc
$ node test/test.js
```
