/*
聚合是一个对象（整体）包含或引用其他对象（部分），但这些部分对象在逻辑上可以独立于整体对象。
本示例：
- 聚合关系：Department类聚合了Employee。Department类包含一个Employee列表，但这些员工的生命周期不依赖于部门。如果部门被销毁，员工对象仍然可以继续存在。这种关系是典型的聚合关系。
- 松散耦合：聚合允许整体和部分对象之间具有较低的耦合度，这使得系统更易于维护和扩展。部分对象可以独立存在，整体对象只是引用它们。
- 部分-整体关系：部门包含员工，但员工可以属于多个部门，也可以独立存在。这种关系使得代码更加灵活，并允许部分对象在整体对象之外被重用。
*/

#include <stdio.h>
#include <stdlib.h>

// 员工结构体
struct Employee
{
  char *name;
};

// 创建员工对象的函数
struct Employee *create_employee(char *name)
{
  struct Employee *employee = (struct Employee *)malloc(sizeof(struct Employee));
  employee->name = name;
  return employee;
}

// 获取员工名字的函数
char *get_name(struct Employee *employee)
{
  return employee->name;
}

// 部门结构体
struct Department
{
  char *department_name;       // 部门名称
  struct Employee **employees; // 部门包含的员工列表
  int num_employees;           // 员工数量
};

// 创建部门对象的函数
struct Department *create_department(char *department_name)
{
  struct Department *department = (struct Department *)malloc(sizeof(struct Department));
  department->department_name = department_name;
  department->employees = NULL;
  department->num_employees = 0;
  return department;
}

// 添加员工到部门的函数
void add_employee(struct Department *department, struct Employee *employee)
{
  department->employees = realloc(department->employees, (department->num_employees + 1) * sizeof(struct Employee *));
  department->employees[department->num_employees] = employee;
  department->num_employees++;
}

// 列出部门中的所有员工名字的函数
void list_employees(struct Department *department)
{
  printf("Employees in %s:\n", department->department_name);
  for (int i = 0; i < department->num_employees; i++)
  {
    printf("%s\n", get_name(department->employees[i]));
  }
}

// 测试验证
int main()
{
  // 创建几个员工对象
  struct Employee *tom = create_employee("Tom");
  struct Employee *jerry = create_employee("Jerry");

  // 创建一个部门，并将员工添加到部门
  struct Department *it_department = create_department("IT Resources");
  add_employee(it_department, tom);
  add_employee(it_department, jerry);

  // 列出部门中的员工
  list_employees(it_department); // 输出：Employees in IT Resources: Tom, Jerry

  // 即使部门被销毁，员工对象仍然可以继续存在
  // 删除部门对象
  free(it_department->employees);
  free(it_department);

  // 输出员工 Tom 的名字
  printf("Employee Tom still exists: %s\n", get_name(tom)); // 输出：Tom

  // 释放员工对象
  free(tom);
  free(jerry);

  return 0;
}

/**
jarry@jarrys-MacBook-Pro aggregation % gcc aggregation_example.c
jarry@jarrys-MacBook-Pro aggregation % ./a.out
Employees in IT Resources:
Tom
Jerry
Employee Tom still exists: Tom
 */