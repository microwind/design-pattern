package test;

import src.*;

public class Test {

  public static void start() {
    /**
     * 组合模式依据树形结构来组合对象，用不同组件来构建整体对象。
     * 不同组件之间有相同的接口约束，有不同的具体实现。
     * 先定义顶级节点，然后陆续加入枝叶节点和叶子节点，这样不断添加，将零散的个体组成一个整体。ss
     */

    // 通过组合模型组合了一个部件，分支和节点可以随意增删
    OrganizationComponent com = new CompanyComposite("西天旅游有限公司");
    OrganizationComponent com1 = new DepartmentComposite("总裁办");
    OrganizationComponent com2 = new DepartmentComposite("行动队");
    OrganizationComponent com3 = new DepartmentComposite("后勤组");
    OrganizationComponent leaf1 = new EmployeeLeaf("唐三藏");
    OrganizationComponent leaf2 = new EmployeeLeaf("孙悟空");
    OrganizationComponent leaf3 = new EmployeeLeaf("猪悟能");
    OrganizationComponent leaf4 = new EmployeeLeaf("沙悟净");

    com.add(com1);
    com.add(com2);
    com.add(com3);

    // leaf1属于com1
    com1.add(leaf1);
    // leaf2, leaf3属于com2
    com2.add(leaf2);
    com2.add(leaf3);

    // 添加再删除
    DepartmentComposite dept1 = new DepartmentComposite("小分队");
    com2.add(dept1);
    EmployeeLeaf tmp1 = new EmployeeLeaf("临时工");
    dept1.add(tmp1);
    dept1.remove(tmp1);

    // leaf4属于com3
    com3.add(leaf4);

    // 执行全部节点动作
    com.operation();

    // 获取某个节点
    OrganizationComponent employee = (EmployeeLeaf) com.getChild(1).getChild(0);
    System.out.println(employee.getName());
  }

  public static void main(String[] args) {
    System.out.println("test start:");
    start();
  }

}

/**
 * 测试
 * jarry@jarrys-MacBook-Pro java % javac test/Test.java
 * jarry@jarrys-MacBook-Pro java % java test/Test
 * test start:
 * src.CompanyComposite CompanyComposite::operation() 西天旅游有限公司
 * src.DepartmentComposite DepartmentComposite::operation() 总裁办
 * src.EmployeeLeaf EmployeeLeaf::operation() 唐三藏
 * src.DepartmentComposite DepartmentComposite::operation() 行动队
 * src.EmployeeLeaf EmployeeLeaf::operation() 孙悟空
 * src.EmployeeLeaf EmployeeLeaf::operation() 猪悟能
 * src.DepartmentComposite DepartmentComposite::operation() 小分队
 * src.DepartmentComposite DepartmentComposite::operation() 后勤组
 * src.EmployeeLeaf EmployeeLeaf::operation() 沙悟净
 * 孙悟空
 */