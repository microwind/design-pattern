import { CompanyComposite } from '../src/CompanyComposite.js'
import { DepartmentComposite } from '../src/DepartmentComposite.js'
import { EmployeeLeaf } from '../src/EmployeeLeaf.js'

export function test() {
  /**
   * 组合模式依据树形结构来组合对象，用不同组件来构建整体对象。
   * 不同组件之间有相同的接口约束，有不同的具体实现。
   * 先定义顶级节点，然后陆续加入枝叶节点和叶子节点，这样不断添加，将零散的个体组成一个整体。ss
   */

  // 通过组合模型组合了一个部件，分支和节点可以随意增删
  const com = new CompanyComposite('西天旅游有限公司')
  const com1 = new DepartmentComposite('总裁办')
  const com2 = new DepartmentComposite('行动队')
  const com3 = new DepartmentComposite('后勤组')
  const leaf1 = new EmployeeLeaf('唐三藏')
  const leaf2 = new EmployeeLeaf('孙悟空')
  const leaf3 = new EmployeeLeaf('猪悟能')
  const leaf4 = new EmployeeLeaf('沙悟净')

  com.add(com1)
  com.add(com2)
  com.add(com3)

  // leaf1属于com1
  com1.add(leaf1)
  // leaf2, leaf3属于com2
  com2.add(leaf2)
  com2.add(leaf3)

  // 添加再删除
  const dept1 = new DepartmentComposite('小分队')
  com2.add(dept1)
  const tmp1 = new EmployeeLeaf('临时工')
  dept1.add(tmp1)
  dept1.remove(tmp1)

  // leaf4属于com3
  com3.add(leaf4)

  // 执行全部节点动作
  com.operation()

  // 获取某个节点
  const employee = com.getChild(1).getChild(0)
  console.log(employee.getName())
}

// 执行测试
;(function () {
  console.log('test start:')
  test()
})()
/**
jarry@jarrys-MacBook-Pro ts % tsc
jarry@jarrys-MacBook-Pro ts % node test/test.js
test start:
CompanyComposite::operation() 西天旅游有限公司
DepartmentComposite::operation() 总裁办
EmployeeLeaf EmployeeLeaf::operation() 唐三藏
DepartmentComposite::operation() 行动队
EmployeeLeaf EmployeeLeaf::operation() 孙悟空
EmployeeLeaf EmployeeLeaf::operation() 猪悟能
DepartmentComposite::operation() 小分队
DepartmentComposite::operation() 后勤组
EmployeeLeaf EmployeeLeaf::operation() 沙悟净
孙悟空
*/
