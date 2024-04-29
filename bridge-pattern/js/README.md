## 代码结构
```shell
- src
  - AbstractShape.js # 桥接抽象类,关联具体的操作接口，供具体类实现
  - RefinedShape.js # 具体桥接类，继承抽象桥接类，扩充了自己的方法
  - DrawTool.js # 工具基础接口，供具体工具类实现
  - DrawStyeA.js # 具体工具类一，负责某类专门处理
  - DrawStyleB.js # 具体工具类二，负责某类专门处理

```

## 测试验证

```shell
$ cd ./bridge-pattern/js
$ node test/test.js
```
