## 代码结构
```shell
- src
  - OrganizationComponent.js # 组合部件抽象类或接口
  - CompanyComposite.js # 具体部件实现之一，树枝构件
  - DepartmentComposite.js # 具体部件实现之一，树枝构件
  - EmployeeLeaf.js # 具体部件的叶子节点，叶子节点不能再含有子节点
```

## 测试验证

```shell
$ cd ./composite-pattern/js
$ node test/test.js
```
