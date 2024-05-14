## 代码结构
```shell
- src
  - Shape.java # 抽象图形父类，抽象方法供重写，非抽象方法尽量不去覆盖
  - Rectangle.java # Rectangle类，继承父类，没有覆盖父类的draw()方法
  - Square.java # Square对象类，继承父类Shape，不重写父类的draw方法

  - LiskovSubstitution_counter.java # 反例，违反了里氏代换原则。为了演示方便把其他类作为子类放在一起
```

## 测试验证

```shell
$ cd ./liskov-substitution/java
$ javac test/Test.java
$ java test/Test
```
