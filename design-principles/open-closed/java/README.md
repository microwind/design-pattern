## 代码结构
```shell
- src
  - AbstractVehicle.java # 车辆抽象类或者是接口，用于具体对象继承或实现，便于统一约束和扩展
  - VehicleFactory.java # 车辆制造工厂，关联抽象汽车类，调用具体车辆的制造方法
  - Bus.java # 巴士类继承自抽象机动车类
  - Car.java # 汽车类继承自抽象机动车类

  - OpenClosed_example.java # 这个例子符合开闭原则。为了演示方便把其他类作为子类放在一起

  - OpenClosed_counter.java # 反例，违反了开闭原则。为了演示方便把其他类作为子类放在一起
```

## 测试验证

```shell
$ cd ./open-closed/java
$ javac test/Test.java
$ java test/Test
```
