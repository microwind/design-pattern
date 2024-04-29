## 代码结构
```shell
- src
  - VehicleFactory.java # 具体工厂类，根据类型创建具体产品
  - Vehicle.java # 具体产品的抽象类或接口
  - Bus.java # 具体产品之一，实现或继承抽象
  - Car.java # 具体产品之一，实现或继承抽象
  - Motorcycle.java # 具体产品之一，实现或继承抽象
  - Van.java # 具体产品之一，实现或继承抽象
  - VehicleType.java # 具体产品的类型
```

## 测试验证

```shell
$ cd ./factory-pattern/java
$ javac test/Test.java
$ java test/Test
```
