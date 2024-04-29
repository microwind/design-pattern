## 代码结构
```shell
- src
  - Flyweight.java # 定义抽象享元接口
  - ConcreteFlyweight.java # 具体享元角色，实现抽象接口，用于共享状态
  - UnsharedConcreteFlyweight.java # 无需共享的角色，实现抽象接口，每次都是新实例
  - FlyweightFactory.java # 享元工厂，储存一个对象共享池
```

## 测试验证

```shell
$ cd ./flyweight-pattern/java
$ javac test/Test.java
$ java test/Test
```
