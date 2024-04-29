## 代码结构
```shell
- src
  - LazySingleton.py # 通过静态方法来实例化对象，当实例化过后就不再生成，存在线程安全问题
  - SingletonSafe.py # 加锁的基于元类的单例模式，基于元类type创建的加强版
  - SingletonSimple.py # 定义全局变量，导入文件时模块的名称空间会被加载到内存
  - SingletonType.py # 基于元类type创建实例，它是type()类的一个实例，同时它本身也是类
```

## 测试验证

```shell
$ cd ./singleton-pattern/python
$ python test/test.py
```
