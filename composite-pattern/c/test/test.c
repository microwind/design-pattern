#include "../src/func.h"

int main(void)
{
    printf("test start:\r\n");
    /**
     * 组合模式依据树形结构来组合对象，用不同组件来构建整体对象。
     * 不同组件之间有相同的接口约束，有不同的具体实现。
     * 先定义顶级节点，然后陆续加入枝叶节点和叶子节点，这样不断添加，将零散的个体组成一个整体。ss
     */

    // 通过组合模型组合了一个部件，分支和节点可以随意增删
    OrganizationComponent *com = (OrganizationComponent *)company_composite_constructor("西天旅游有限公司");
    OrganizationComponent *com1 = (OrganizationComponent *)department_composite_constructor("总裁办");
    OrganizationComponent *com2 = (OrganizationComponent *)department_composite_constructor("行动队");
    OrganizationComponent *com3 = (OrganizationComponent *)department_composite_constructor("后勤组");

    OrganizationComponent *leaf1 = (OrganizationComponent *)employee_leaf_constructor("唐三藏");
    OrganizationComponent *leaf2 = (OrganizationComponent *)employee_leaf_constructor("孙悟空");
    OrganizationComponent *leaf3 = (OrganizationComponent *)employee_leaf_constructor("猪悟能");
    OrganizationComponent *leaf4 = (OrganizationComponent *)employee_leaf_constructor("沙悟净");

    com->add(com, com1);
    com->add(com, com2);
    com->add(com, com3);

    // leaf1属于com1
    com1->add(com1, leaf1);
    // leaf2, leaf3属于com2
    com2->add(com2, leaf2);
    com2->add(com2, leaf3);

    // 添加再删除
    DepartmentComposite *dept1 = department_composite_constructor("小分队");
    com2->add(com2, (OrganizationComponent *)dept1);
    EmployeeLeaf *tmp1 = employee_leaf_constructor("临时工");
    dept1->add((OrganizationComponent *)dept1, (OrganizationComponent *)tmp1);
    dept1->remove((OrganizationComponent *)dept1, (OrganizationComponent *)tmp1);

    // leaf4属于com3
    com3->add(com3, leaf4);

    // 执行全部节点动作
    com->operation(com);

    // 获取某个节点
    OrganizationComponent *dept2 = com->get_child(com, 1);
    EmployeeLeaf *employee_child1 = (EmployeeLeaf *)dept2->get_child(dept2, 0);
    printf("\r\n [employee->name=%s]", employee_child1->name);

    free(com);
    free(com1);
    free(com2);
    free(com3);

    free(leaf1);
    free(leaf2);
    free(leaf3);
    free(leaf4);

    return 0;
}

// jarry@jarrys-MacBook-Pro c % gcc test/test.c src/*.c
// jarry@jarrys-MacBook-Pro c % ./a.out
/**
test start:

 CompanyComposite::operation() [name=西天旅游有限公司]
 DepartmentComposite::operation() [name=总裁办]
 EmployeeLeaf::operation() [name=唐三藏]
 DepartmentComposite::operation() [name=行动队]
 EmployeeLeaf::operation() [name=孙悟空]
 EmployeeLeaf::operation() [name=猪悟能]
 DepartmentComposite::operation() [name=小分队]
 DepartmentComposite::operation() [name=后勤组]
 EmployeeLeaf::operation() [name=沙悟净]
 [employee->name=孙悟空]%
 */