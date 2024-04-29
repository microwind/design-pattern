## 代码结构
```shell
- src
  - EagerSingleton.js # 饿汉模式，直接返回已经初始化的实例
  - LazySingleton.js # 懒汉模式，延迟实例化，请求实例时判断，如果已经实例化过就直接返回
  - LazySingletonObject.js # 创建对象，不是class，无需实例化，直接返回对象
```

## 测试验证

```shell
$ cd ./singleton-pattern/js
$ node test/test.js
```
