## 代码结构
```shell
- src
  - AbstractFacade.js # 外观模式的接口或抽象类，可选
  - Facade.js # 外观模式实现类，继承基础抽象，是外部调用与内部子系统的衔接层
  - EncodeModule.js # 内部模块类之一
  - FileModule.js # 内部模块类之一
  - NetworkModule.js # 内部模块类之一
```

## 测试验证

```shell
$ cd ./facade-pattern/js
$ node test/Test.js
```
