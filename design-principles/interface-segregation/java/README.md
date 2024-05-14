## 代码结构
```shell
- src
  - DeviceController.java # 电器设备的基础控制接口，把一些基础方法提取出来【可选】
  - LightController.java # Light控制接口，包括TV需要的控制方法，供Light具体对象实现
  - Light.java # Light实现类，实现Light控制接口的全部方法
  - TVController.java # TV控制接口，包括TV需要的控制方法，供TV具体对象实现
  - TV.java # TV实现类，实现TV控制接口的全部方法

  - InterfaceSegregation_counter.java # 反例，违反了接口隔离原则。为了演示方便把其他类作为子类放在一起
```

## 测试验证

```shell
$ cd ./interface-segregation/java
$ javac test/Test.java
$ java test/Test
```
