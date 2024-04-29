## 代码结构
```shell
- src
  - VehicleFactory.py # 具体工厂类，根据类型创建具体产品
  - Vehicle.py # 具体产品的抽象类或接口
  - Bus.py # 具体产品之一，实现或继承抽象
  - Car.py # 具体产品之一，实现或继承抽象
  - Motorcycle.py # 具体产品之一，实现或继承抽象
  - Van.py # 具体产品之一，实现或继承抽象
```

## 测试验证

```shell
$ cd ./factory-pattern/python
$ python test/test.py
```
