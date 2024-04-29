## 代码结构
```shell
- src
  - func.h # 头文件，定义接口与数据
  - observer.c # 观察者接口或抽象类，定义在head，可选
  - concrete_observer.c # 具体的观察者实现类，也可以看成订阅者，关联对应的主题类
  - concrete_observer2.c # 具体的观察者实现类，也可以看成订阅者，关联对应的主题类
  - subject.c # 抽象主题类或者接口，定义在head，可选
  - concrete_subject.c # 具体主题类，也是发布者，发布内容时关联的观察者自动更新
```

## 测试验证

```shell
$ cd ./observer-pattern/c
$ gcc test/test.c ./src/*.c
$ ./a.out
```
