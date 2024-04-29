## 代码结构
```shell
- src
  - AbstractHandler.js # 责任链抽象类或接口，定义调用链，供具体类继承和实现
  - AuthHandler.js # 具体事件处理类之一，继承抽象类
  - RequestHandler.js # 具体事件处理类之一，继承抽象类
  - UserHandler.js # 具体事件处理类之一，继承抽象类
```

## 测试验证

```shell
$ cd ./chain-responsibility/js
$ node test/test.js
```
