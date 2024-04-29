## 代码结构
```shell
- src
  - DoubleCheckSingleton.go # 安全懒汉模式的升级版，通过sync的Mutex实现双重检验
  - EagerSingleton.go # 饿汉模式单例。定义私有变量，用来保存实例
  - LazySingleton.go # 懒汉模式单例，延迟实例化，但不是很安全
  - LazySingletonSafe.go # 懒汉模式单例，延迟实例化，导入sync包，利用once来提升安全
  - SingletonInterface.go # 懒汉模式单例，延迟实例化简单版，增加了一个接口
```

## 测试验证

```shell
$ cd ./singleton-pattern/go
$ go run test/test.go
```
