## 代码结构
```shell
- src
  - Customer.java # Customer类，减轻逻辑，调用购物车来实现商品的购买，不直接跟商品交互
  - Product.java # Product对象类，只有商品本身信息
  - ShoppingCart.java # ShoppingCart类，负责商品校验价格计算等逻辑，是顾客和商品之间的桥梁

  - LawDemeter_counter.java # 反例，违反了迪米特原则。为了演示方便把其他类作为子类放在一起
```

## 测试验证

```shell
$ cd ./law-of-demeter/java
$ javac test/Test.java
$ java test/Test
```
