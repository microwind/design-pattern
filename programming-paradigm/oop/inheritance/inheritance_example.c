/*
继承即子类继承父类的特征和行为，使得子类对象（实例）具有父类的属性和方法。
这个例子展示了继承的多种应用，包括代码复用、层次结构和多态。
本示例：
- 基类和子类：Employee是基类，Manager和Engineer是子类。子类继承了基类的属性和方法。
- 代码复用：子类通过继承自动获得了基类的属性和方法，这减少了代码重复。
- 方法重写：子类重写了基类的displayInfo方法，提供了更具体的信息。
- 多态：通过父类引用子类对象，代码可以灵活地使用不同的子类，而无需明确指定子类的类型。这允许代码在运行时根据实际对象类型选择适当的行为。
*/

#include <stdio.h>
#include <stdlib.h>

// 定义基类：雇员
typedef struct
{
    char *name;    // 雇员的名字
    double salary; // 雇员的工资
} Employee;

// 基类的方法，打印雇员信息
void display_info(Employee *emp)
{
    printf("Employee: %s, 薪水: %.2f\n", emp->name, emp->salary);
}

// 子类：经理，继承自雇员
typedef struct
{
    Employee base;    // 继承自雇员
    char *department; // 经理负责的部门
} Manager;

// 经理的方法，打印经理信息
void display_info_manager(Manager *mgr)
{
    printf("Manager: %s, 薪水: %.2f, 部门: %s\n", mgr->base.name, mgr->base.salary, mgr->department);
}

// 经理特有的方法，管理团队
void manage_team(Manager *mgr)
{
    printf("%s 管理 %s 部门.\n", mgr->base.name, mgr->department);
}

// 子类：工程师，继承自雇员
typedef struct
{
    Employee base;   // 继承自雇员
    char *expertise; // 工程师的专业领域
} Engineer;

// 工程师的方法，打印工程师信息
void display_info_engineer(Engineer *eng)
{
    printf("Engineer: %s, 薪水: %.2f, 职位: %s\n", eng->base.name, eng->base.salary, eng->expertise);
}

// 工程师特有的方法，展示技能
void demonstrate_skills(Engineer *eng)
{
    printf("%s 专业技能： %s.\n", eng->base.name, eng->expertise);
}

int main()
{
    // 创建基类对象：雇员
    Employee emp = {"Tom", 50000};
    display_info(&emp); // 输出：Employee: Tom, 薪水: 50000

    // 创建子类对象：经理
    Manager mgr = {{"Jack", 80000}, "Engineering"};
    display_info_manager(&mgr); // 输出：Manager: Jack, 薪水: 80000, 部门: Engineering
    manage_team(&mgr);          // 输出：Jack 管理的部门.

    // 创建子类对象：工程师
    Engineer eng = {{"Charlie", 60000}, "Software Development"};
    display_info_engineer(&eng); // 输出：Engineer: Charlie, 薪水: 60000, 职位: Software Development
    demonstrate_skills(&eng);    // 输出：Charlie 专业技能： Software Development.

    return 0;
}

/**
jarry@jarrys-MacBook-Pro inheritance % gcc inheritance_example.c 
jarry@jarrys-MacBook-Pro inheritance % ./a.out 
Employee: Tom, 薪水: 50000.00
Manager: Jack, 薪水: 80000.00, 部门: Engineering
Jack 管理 Engineering 部门.
Engineer: Charlie, 薪水: 60000.00, 职位: Software Development
Charlie 专业技能： Software Development.
 */