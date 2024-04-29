## 代码结构
```shell
- src
  - SingletonDoubleCheck.java # 双重检验懒汉单例，单例模式最优方案，线程安全并且效率高 
  - SingletonEager.java # 饿汉式（线程安全），当类被加载的时候会初始化，静态变量被创建并分配内存空间
  - SingletonInner.java # 静态内部类方式，既实现延迟加载，也保障线程安全
  - SingletonLazy.java # 懒汉式也叫饱汉式，增加synchronized来保证线程安全
```

## 测试验证

```shell
$ cd ./singleton-pattern/java
$ javac test/Test.java
$ java test/Test
```
