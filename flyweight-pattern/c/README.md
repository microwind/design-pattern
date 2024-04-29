## 代码结构
```shell
- src
  - func.h # 头文件，定义接口与数据
  - flyweight.c # 定义抽象享元接口，定义在head
  - concrete_flyweight.c # 具体享元角色，实现抽象接口，用于共享状态
  - unshared_concrete_flyweight.c # 无需共享的角色，实现抽象接口，每次都是新实例
  - flyweight_factory.c # 享元工厂，储存一个对象共享池
```

## 测试验证

```shell
$ cd ./flyweight-pattern/c
$ gcc test/test.c src/*.c
$ ./a.out
```
