## 代码结构
```shell
- src
  - OrganizationComponent.py # 组合部件抽象类或接口
  - CompanyComposite.py # 具体部件实现之一，树枝构件
  - DepartmentComposite.py # 具体部件实现之一，树枝构件
  - EmployeeLeaf.py # 具体部件的叶子节点，叶子节点不能再含有子节点
```

## 测试验证

```shell
$ cd ./composite-pattern/python
$ python test/test.py
```
