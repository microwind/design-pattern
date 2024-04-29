## 代码结构
```shell
- src
  - AbstractHandler.java # 责任链抽象类或接口，定义调用链，供具体类继承和实现
  - AuthHandler.java # 具体事件处理类之一，继承抽象类
  - RequestHandler.java # 具体事件处理类之一，继承抽象类
  - UserHandler.java # 具体事件处理类之一，继承抽象类
```

## 测试验证

```shell
$ cd ./chain-responsibility/java
$ javac test/Test.java
$ java test/Test
```
