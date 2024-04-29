## 代码结构
```shell
- src
  - AbstractFactory.py # 抽象工厂基类，定义工厂概念，被具体的工厂所继承
  - ShopFactory.py # 具体工厂类之一，负责Shop生产，继承抽象工厂
  - VehicleFactory.py # 具体工厂类之一，负责Vehichle生产，继承抽象工厂
  - FactoryCreator.py # 工厂创建类，根据产品类别创建不同的工厂
  + shop # Shop类产品文件夹
    - Shop.py # Shop基类
    - AgencyShop.ajva # Shop具体实现之一
    - DirectSale.py # Shop具体实现之一
    - SupermarketShop.py # Shop具体实现之一
  + vehicle # Vehicle类产品文件夹
    - Vehicle.py # Vehicle基类
    - Bus.py # Vehicle具体实现之一
    - Car.py # Vehicle具体实现之一
    - Motorcycle.py # Vehicle具体实现之一
    - Van # Vehicle具体实现之一
```

## 测试验证

```shell
$ cd ./abstract-factory/python
$ python test/test.py
```
