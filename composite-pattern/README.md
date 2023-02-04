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

# 代码

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
```

## 更多语言版本
不同语言实现设计模式：[https://github.com/microwind/design-pattern](https://github.com/microwind/design-pattern)