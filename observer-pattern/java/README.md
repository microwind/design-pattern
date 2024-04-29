## 代码结构
```shell
- src
  - ObserverAPI.java # 观察者接口或抽象类，负责定义观察者基本规范
  - ConcreteObserver.java # 具体的观察者实现类，也可以看成订阅者，关联对应的主题类
  - ConcreteObserver2.java # 具体的观察者实现类，也可以看成订阅者，关联对应的主题类
  - Subject.java # 抽象主题类或者接口，定义主题发布基本逻辑，供具体主题类继承
  - ConcreteSubject.java # 具体主题类，也是发布者，发布内容时关联的观察者自动更新
```

## 测试验证

```shell
$ cd ./observer-pattern/java
$ javac test/Test.java
$ java test/Test
```
