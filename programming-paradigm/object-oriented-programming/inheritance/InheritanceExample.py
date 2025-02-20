# -*- coding: utf-8 -*-
'''
继承即子类继承父类的特征和行为，使得子类对象（实例）具有父类的属性和方法。
这个例子展示了继承的多种应用，包括代码复用、层次结构和多态。
本示例：
- 基类和子类：Employee是基类，Manager和Engineer是子类。子类继承了基类的属性和方法。
- 代码复用：子类通过继承自动获得了基类的属性和方法，这减少了代码重复。
- 方法重写：子类重写了基类的displayInfo方法，提供了更具体的信息。
- 多态：通过父类引用子类对象，代码可以灵活地使用不同的子类，而无需明确指定子类的类型。这允许代码在运行时根据实际对象类型选择适当的行为。 
'''

# 定义基类：雇员


class Employee:
    def __init__(self, name, salary):
        self.name = name  # 初始化雇员名字
        self.salary = salary  # 初始化雇员工资

    # 基类中的方法，打印雇员信息
    def display_info(self):
        print(f"Employee: {self.name}, 薪水: {self.salary}")

# 子类：经理，继承自雇员


class Manager(Employee):
    def __init__(self, name, salary, department):
        super().__init__(name, salary)  # 调用父类的构造方法
        self.department = department  # 初始化部门

    # 覆写父类的方法，打印经理信息
    def display_info(self):
        print(
            f"Manager: {self.name}, 薪水: {self.salary}, 部门: {self.department}")

    # 经理特有的方法，管理团队
    def manage_team(self):
        print(f"{self.name} 管理 {self.department} 部门.")

# 子类：工程师，继承自雇员


class Engineer(Employee):
    def __init__(self, name, salary, expertise):
        super().__init__(name, salary)  # 调用父类的构造方法
        self.expertise = expertise  # 初始化专业领域

    # 覆写父类的方法，打印工程师信息
    def display_info(self):
        print(
            f"Engineer: {self.name}, 薪水: {self.salary}, 职位: {self.expertise}")

    # 工程师特有的方法，展示技能
    def demonstrate_skills(self):
        print(f"{self.name} 专业技能： {self.expertise}.")


# 创建基类对象：雇员
emp = Employee("Tom", 50000)
emp.display_info()  # 输出：Employee: Tom, 薪水: 50000

# 创建子类对象：经理
mgr = Manager("Jack", 80000, "Engineering")
mgr.display_info()  # 输出：Manager: Jack, 薪水: 80000, 部门: Engineering
mgr.manage_team()  # 输出：Jack 管理的部门.

# 创建子类对象：工程师
eng = Engineer("Charlie", 60000, "Software Development")
eng.display_info()  # 输出：Engineer: Charlie, 薪水: 60000, 职位: Software Development
eng.demonstrate_skills()  # 输出：Charlie 专业技能： Software Development.
