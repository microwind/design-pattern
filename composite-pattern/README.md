# 【组合设计模式详解】C/Java/JS/Go/Python/TS不同语言实现

# 简介
组合模式（Composite Pattern），又叫部分整体模式，是一种结构型设计模式。用于把一组类似的对象当作一个单一的对象来看。组合模式依据树形结构来组合对象，用不同组件来构建某个部分或整体对象。

 如果你需要实现树状对象结构，可以使用组合模式。如果你希望客户端代码以相同方式处理简单和复杂元素，可以使用该模式。

# 作用
1. 符合开闭原则。无需更改现有代码，就可以在应用中添加新元素，使之成为对象树的一部分。
2. 模糊了简单元素和复杂元素的概念，程序可以像处理简单元素一样来处理复杂元素，从而使得程序与复杂元素的内部结构解耦。

# 实现步骤
1. 创建抽象构件（Component）接口，用于声明树叶构件和树枝构件的默认行为。
2. 创建树枝构件（Composite）角色 / 中间构件：是组合中的分支节点对象，它有子节点，用于继承和实现抽象构件。它的主要作用是存储和管理子部件，通常包含 Add()、Remove()、GetChild() 等方法。
3. 定义树叶构件（Leaf）角色：是组合中的叶子节点对象，它没有子节点，用于继承或实现抽象构件。

# UML
<img src="../docs/uml/composite-pattern.png">

# Java语言代码

## 基础部件接口
```java
// OrganizationComponent.java 定义部件接口或抽象类，分支和叶子节点遵循该类约定
public interface OrganizationComponent {
   public void add(OrganizationComponent component);

   public void remove(OrganizationComponent component);

   public OrganizationComponent getChild(int index);

   public void operation();

   public String getName();
}
```

## 具体部件实现
```java
// CompanyComposite.java 实现部件的树枝构件1
public class CompanyComposite implements OrganizationComponent {

   private String name;
   private List<OrganizationComponent> children = new ArrayList<OrganizationComponent>();

   public CompanyComposite(String name) {
      this.name = name;
   }

   public void add(OrganizationComponent component) {
      children.add(component);
   }

   public void remove(OrganizationComponent component) {
      children.remove(component);
   }

   public OrganizationComponent getChild(int index) {
      return children.get(index);
   }

   public void operation() {
      System.out.println(this.getClass().getName() + " CompanyComposite::operation() " + this.name);
      for (Object component : children) {
         ((OrganizationComponent) component).operation();
      }
   }

   public String getName() {
      return name;
   }
}
```

```java
// DepartmentComposite.java  实现部件的树枝构件2
public class DepartmentComposite implements OrganizationComponent {

   private String name;
   private List<OrganizationComponent> children = new ArrayList<OrganizationComponent>();

   public DepartmentComposite(String name) {
      this.name = name;
   }

   public void add(OrganizationComponent component) {
      children.add(component);
   }

   public void remove(OrganizationComponent component) {
      children.remove(component);
   }

   public OrganizationComponent getChild(int index) {
      return children.get(index);
   }

   public void operation() {
      System.out.println(this.getClass().getName() + " DepartmentComposite::operation() " + this.name);
      for (Object component : children) {
         ((OrganizationComponent) component).operation();
      }
   }

   public String getName() {
      return name;
   }
}
```

```java
// EmployeeLeaf.java 实现部件的叶子节点，叶子节点不能再含有子节点
public class EmployeeLeaf implements OrganizationComponent {

   private String name;

   public EmployeeLeaf(String name) {
      this.name = name;
   }

   // 叶子节点不能再增加内容
   public void add(OrganizationComponent component) {
      System.out.println("Leaf can't add.");
   }

   // 叶子节点没有移除内容
   public void remove(OrganizationComponent component) {
      System.out.println("Leaf can't remove.");
   }

   // 叶子节点无获取子节点
   public OrganizationComponent getChild(int index) {
      System.out.println("Leaf can't getChild.");
      return null;
   }

   public void operation() {
      System.out.println(this.getClass().getName() + " EmployeeLeaf::operation() " + this.name);
   }

   public String getName() {
      return name;
   }
}
```
## 测试调用
```java
    /**
     * 组合模式依据树形结构来组合对象，用不同组件来构建整体对象。
     * 不同组件之间有相同的接口约束，有不同的具体实现。
     * 先定义顶级节点，然后陆续加入枝叶节点和叶子节点，这样不断添加，将零散的个体组成一个整体。
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
```

# C语言代码

## func.h 自定义头文件
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 定义部件接口或抽象类，分支和叶子节点遵循该类约定
typedef struct OrganizationComponent
{
    char name[200];
    void (*add)(struct OrganizationComponent *, struct OrganizationComponent *);
    void (*remove)(struct OrganizationComponent *, struct OrganizationComponent *);
    struct OrganizationComponent *(*get_child)(struct OrganizationComponent *, int);
    void (*operation)(struct OrganizationComponent *);
    int children_size;
    struct OrganizationComponent **children;
    // 如果是柔型数组，则自动扩展数组长度，但可能导致出现乱码现象，故采取固定长度数组
    // struct OrganizationComponent *children[];
} OrganizationComponent;
void add_component(OrganizationComponent *, OrganizationComponent *);
void remove_component(OrganizationComponent *, OrganizationComponent *);
OrganizationComponent *get_child_component(OrganizationComponent *, int);
void print_children(OrganizationComponent *children[], int children_size);

// 实现部件的树枝构件1
typedef struct CompanyComposite
{
    char name[200];
    void (*add)(struct OrganizationComponent *, struct OrganizationComponent *);
    void (*remove)(struct OrganizationComponent *, struct OrganizationComponent *);
    struct OrganizationComponent *(*get_child)(struct OrganizationComponent *, int);
    void (*operation)(struct CompanyComposite *);
    int children_size;
    struct OrganizationComponent **children;
} CompanyComposite;
CompanyComposite *company_composite_constructor(char *name);

// 实现部件的树枝构件2
typedef struct DepartmentComposite
{
    char name[200];
    void (*add)(struct OrganizationComponent *, struct OrganizationComponent *);
    void (*remove)(struct OrganizationComponent *, struct OrganizationComponent *);
    struct OrganizationComponent *(*get_child)(struct OrganizationComponent *, int);
    void (*operation)(struct DepartmentComposite *);
    int children_size;
    struct OrganizationComponent **children;
} DepartmentComposite;
DepartmentComposite *department_composite_constructor(char *name);

// 实现部件的叶子节点，叶子节点不能再含有子节点
typedef struct EmployeeLeaf
{
    char name[200];
    void (*add)(struct OrganizationComponent *, struct OrganizationComponent *);
    void (*remove)(struct OrganizationComponent *, struct OrganizationComponent *);
    struct OrganizationComponent *(*get_child)(struct OrganizationComponent *, int);
    void (*operation)(struct EmployeeLeaf *);
    int children_size;
    struct OrganizationComponent **children;
} EmployeeLeaf;
EmployeeLeaf *employee_leaf_constructor(char *name);

```

## 基础部件接口
```c
// organization_component.c 定义部件接口或抽象类，分支和叶子节点遵循该类约定
#include "func.h"

// 定义部件接口或抽象类，分支和叶子节点遵循该类约定
// C语言没有接口和抽象类，用struct替代，同时把公共函数声明在这里

// 添加一个组件到子节点中
void add_component(OrganizationComponent *parent, OrganizationComponent *component)
{
  // 先将原数组保留下来
  OrganizationComponent **old_children = parent->children;
  parent->children_size += 1;
  // 新申请空间给子节点数组
  parent->children = (OrganizationComponent **)calloc(parent->children_size, sizeof(OrganizationComponent *));
  for (int i = 0; i < parent->children_size - 1; i++)
  {
    parent->children[i] = old_children[i];
  }
  // 将组件追加到子节点数组中
  parent->children[parent->children_size - 1] = component;
  free(old_children);
}

// 移除第一个匹配的子节点
void remove_component(OrganizationComponent *parent, OrganizationComponent *component)
{
  int size = parent->children_size;
  // 初始化组件id大于数组长度
  int com_idx = size;
  for (int i = 0; i < size; i++)
  {
    // 找到第一个匹配的组件下标
    if (parent->children[i] == component)
    {
      com_idx = i;
    }

    // 自匹配项开始，后项逐个往前移动1位
    if (i >= com_idx)
    {
      parent->children[i] = parent->children[i + 1];
      // 最后一项置空且总长度减少1位
      if (i == size - 1)
      {
        parent->children[i] = NULL;
        parent->children_size -= 1;
      }
    }
  }
}

// 打印全部子节点
void print_children(OrganizationComponent *children[], int children_size)
{
  for (int i = 0; i < children_size; i++)
  {
    printf("\r\n    children[%d]=%s", i, children[i]->name);
  }
}

// 根据下标获取子节点
OrganizationComponent *get_child_component(OrganizationComponent *component, int index)
{
  return component->children[index];
}
```

## 具体部件实现
```c
// company_composite.c 实现部件的树枝构件1
#include "func.h"

// 实现部件的树枝构件1
void company_composite_operation(CompanyComposite *component)
{
  printf("\r\n CompanyComposite::operation() [name=%s]", component->name);
  print_children(component->children, component->children_size);
  for (int i = 0; i < component->children_size; i++)
  {
    if (component->children[i] != NULL)
    {
      component->children[i]->operation(component->children[i]);
    }
  }
}

// 创建CompanyComposite对象
CompanyComposite *company_composite_constructor(char *name)
{
  OrganizationComponent *component = (OrganizationComponent *)malloc(sizeof(OrganizationComponent));
  strncpy(component->name, name, 200);
  component->add = &add_component;
  component->remove = &remove_component;
  component->children_size = 0;
  component->get_child = &get_child_component;
  // 转为CompanyComposite
  CompanyComposite *company_composite = (CompanyComposite *)component;
  company_composite->operation = &company_composite_operation;
  return company_composite;
}
```

```c
// department_composite.c  实现部件的树枝构件2
#include "func.h"

// 实现部件的树枝构件2
void department_composite_operation(DepartmentComposite *component)
{
  printf("\r\n DepartmentComposite::operation() [name=%s]", component->name);
  print_children(component->children, component->children_size);
  for (int i = 0; i < component->children_size; i++)
  {
    if (component->children[i] != NULL)
    {
      component->children[i]->operation(component->children[i]);
    }
  }
}

// 创建DepartmentComposite对象
DepartmentComposite *department_composite_constructor(char *name)
{
  OrganizationComponent *component = (OrganizationComponent *)malloc(sizeof(OrganizationComponent));
  strncpy(component->name, name, 200);
  component->add = &add_component;
  component->remove = &remove_component;
  component->children_size = 0;
  component->get_child = &get_child_component;
  // 转为DepartmentComposite
  DepartmentComposite *department_composite = (DepartmentComposite *)component;
  department_composite->operation = &department_composite_operation;
  return department_composite;
}
```

```c
// employee_leaf.c 实现部件的叶子节点，叶子节点不能再含有子节点
#include "func.h"

// 实现部件的叶子节点，叶子节点不能再含有子节点

// 叶子节点不能再增加内容
void add_leaf_component(OrganizationComponent *parent, OrganizationComponent *component)
{
  printf("\r\n Leaf can't add.");
}

// 叶子节点没有移除内容
void remove_leaf_component(OrganizationComponent *parent, OrganizationComponent *component)
{
  printf("\r\n Leaf can't remove.");
}

// 叶子节点不能获取子节点
OrganizationComponent *get_leaf_child_component(OrganizationComponent *component, int index)
{
  printf("\r\n Leaf can't get_child.");
  return NULL;
}

// 子节点的操作函数
void employee_leaf_operation(EmployeeLeaf *component)
{
  printf("\r\n EmployeeLeaf::operation() [name=%s]", component->name);
}

// 创建EmployeeLeaf对象
EmployeeLeaf *employee_leaf_constructor(char *name)
{
  OrganizationComponent *component = (OrganizationComponent *)malloc(sizeof(OrganizationComponent));
  strncpy(component->name, name, 200);
  component->children_size = 0;
  component->add = &add_leaf_component;
  component->remove = &remove_leaf_component;
  component->get_child = &get_leaf_child_component;
  // 转为EmployeeLeaf
  EmployeeLeaf *employee_leaf = (EmployeeLeaf *)component;
  employee_leaf->operation = &employee_leaf_operation;
  return employee_leaf;
}
```

## 测试调用
```c
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

```

## 更多语言版本
不同语言实现设计模式源码，请查看：[https://github.com/microwind/design-pattern](https://github.com/microwind/design-pattern)