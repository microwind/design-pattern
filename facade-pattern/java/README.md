## 代码结构
```shell
- src
  - AbstractFacade.java # 外观模式的接口或抽象类，可选
  - Facade.java # 外观模式实现类，继承基础抽象，是外部调用与内部子系统的衔接层
  - EncodeModule.java # 内部模块类之一
  - FileModule.java # 内部模块类之一
  - NetworkModule.java # 内部模块类之一
```

## 测试验证

```shell
$ cd ./facade-pattern/java
$ javac test/Test.java
$ java test/Test
```
