## 代码结构
```shell
- src
  - Caretaker.ts # 负责人(Caretaker)角色，只负责保存备忘录记录，不能修改备忘录对象的内容
  - Memento.ts # 备忘录(Memento)角色，负责存储发起人传入的状态
  - Originator.ts # 发起人(Originator)负责生成状态快照，即利用一个新备忘录对象将自己的内部状态存储起来
```

## 测试验证

```shell
$ cd ./memento-pattern/ts
$ tsc
$ node test/test.js
```
