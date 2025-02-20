/*
继承即子类继承父类的特征和行为，使得子类对象（实例）具有父类的属性和方法。
这个例子展示了继承的多种应用，包括代码复用、层次结构和多态。
本示例：
- 基类和子类：Employee是基类，Manager和Engineer是子类。子类继承了基类的属性和方法。
- 代码复用：子类通过继承自动获得了基类的属性和方法，这减少了代码重复。
- 方法重写：子类重写了基类的displayInfo方法，提供了更具体的信息。
- 多态：通过父类引用子类对象，代码可以灵活地使用不同的子类，而无需明确指定子类的类型。这允许代码在运行时根据实际对象类型选择适当的行为。 
*/

// 基类：雇员
class Employee {
    protected String name; // 雇员的名字
    protected double salary; // 雇员的工资

    public Employee(String name, double salary) {
        this.name = name; // 初始化雇员名字
        this.salary = salary; // 初始化雇员工资
    }

    // 基类中的方法，打印雇员信息
    public void displayInfo() {
        System.out.println("Employee: " + name + ", 薪水: " + salary);
    }

    // 基类中的方法，计算年薪
    public double getAnnualSalary() {
        return salary * 12; // 一年12个月的工资
    }
}

// 子类：经理，继承自雇员
class Manager extends Employee {
    private String department; // 经理负责的部门

    public Manager(String name, double salary, String department) {
        super(name, salary); // 调用父类的构造方法
        this.department = department; // 初始化部门
    }

    // 覆写父类的方法，打印经理信息
    @Override
    public void displayInfo() {
        System.out.println("Manager: " + name + ", 薪水: " + salary + ", 部门: " + department);
    }

    // 经理特有的方法，管理团队
    public void manageTeam() {
        System.out.println(name + " 管理 " + department + " 部门.");
    }
}

// 子类：工程师，继承自雇员
class Engineer extends Employee {
    private String expertise; // 工程师的专业领域

    public Engineer(String name, double salary, String expertise) {
        super(name, salary); // 调用父类的构造方法
        this.expertise = expertise; // 初始化专业领域
    }

    // 覆写父类的方法，打印工程师信息
    @Override
    public void displayInfo() {
        System.out.println("Engineer: " + name + ", 薪水: " + salary + ", 职位: " + expertise);
    }

    // 工程师特有的方法，展示技能
    public void demonstrateSkills() {
        System.out.println(name + " 专业技能： " + expertise + ".");
    }
}

public class InheritanceExample {
    public static void main(String[] args) {
        // 创建基类对象：雇员
        Employee emp = new Employee("Tom", 50000);
        emp.displayInfo(); // 输出：Employee: Tom, 薪水: 50000

        // 创建子类对象：经理
        Manager mgr = new Manager("Jack", 80000, "Engineering");
        mgr.displayInfo(); // 输出：Manager: Jack, 薪水: 80000, 部门: Engineering
        mgr.manageTeam(); // 输出：Jack 管理的部门.

        // 创建子类对象：工程师
        Engineer eng = new Engineer("Charlie", 60000, "Software Development");
        eng.displayInfo(); // 输出：Engineer: Charlie, 薪水: 60000, 职位: Software Development
        eng.demonstrateSkills(); // 输出：Charlie 专业技能： Software Development.

        // 使用多态，父类引用子类对象
        Employee polymorphicEmployee = new Manager("David", 90000, "Marketing");
        polymorphicEmployee.displayInfo(); // 输出：Manager: David, 薪水: 90000, 部门: Marketing

        polymorphicEmployee = new Engineer("Eve", 70000, "Data Science");
        polymorphicEmployee.displayInfo(); // 输出：Engineer: Eve, 薪水: 70000, 职位: Data Science
    }
}