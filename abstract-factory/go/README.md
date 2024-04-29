## 代码结构
```shell
- src
  - AbstractFactory.go # 抽象工厂类，定义工厂概念，被具体的工厂所继承
  - ShopFactory.go # 具体工厂类之一，负责Shop生产，继承抽象工厂
  - VehicleFactory.go # 具体工厂类之一，负责Vehichle生产，继承抽象工厂
  - FactoryCreator.go # 工厂创建类，根据产品类别创建不同的工厂
  + shop # Shop类产品文件夹
    - Shop.go # Shop接口
    - AgencyShop.ajva # Shop具体实现之一
    - DirectSale.go # Shop具体实现之一
    - SupermarketShop.go # Shop具体实现之一
  + vehicle # Vehicle类产品文件夹
    - Vehicle.go # Vehicle接口
    - Bus.go # Vehicle具体实现之一
    - Car.go # Vehicle具体实现之一
    - Motorcycle.go # Vehicle具体实现之一
    - Van # Vehicle具体实现之一
    - VehicleType.go # Vehicle的类型
```

## 测试验证

```shell
$ cd ./abstract-factory/go
$ go run test/test.go
```
