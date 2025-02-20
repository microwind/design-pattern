/*
继承即子类继承父类的特征和行为，使得子类对象（实例）具有父类的属性和方法。
这个例子展示了继承的多种应用，包括代码复用、层次结构和多态。
本示例：
- 基类和子类：Employee是基类，Manager和Engineer是子类。子类继承了基类的属性和方法。
- 代码复用：子类通过继承自动获得了基类的属性和方法，这减少了代码重复。
- 方法重写：子类重写了基类的displayInfo方法，提供了更具体的信息。
- 多态：通过父类引用子类对象，代码可以灵活地使用不同的子类，而无需明确指定子类的类型。这允许代码在运行时根据实际对象类型选择适当的行为。
*/

// Go没有class，也没有extends关键词来实现类的继承。
// 只能通过匿名类来实现对父struct属性的聚合。
// 在面向对象里继承有好的一面，也要不好的一面，继承泛滥将不好维护代码。
// 因此Go语言采取的是聚合而非继承的模式。

package main

import "fmt"

// 定义基类：雇员
type Employee struct {
    name   string  // 雇员的名字
    salary float64 // 雇员的工资
}

// 基类的方法，打印雇员信息
func (e *Employee) displayInfo() {
    fmt.Printf("Employee: %s, 薪水: %.2f\n", e.name, e.salary)
}

// 子类：经理，继承自雇员
type Manager struct {
    Employee          // 匿名字段，继承自雇员
    department string // 经理负责的部门
}

// 经理的方法，打印经理信息
func (m *Manager) displayInfo() {
    fmt.Printf("Manager: %s, 薪水: %.2f, 部门: %s\n", m.name, m.salary, m.department)
}

// 经理特有的方法，管理团队
func (m *Manager) manageTeam() {
    fmt.Printf("%s 管理 %s 部门.\n", m.name, m.department)
}

// 子类：工程师，继承自雇员
type Engineer struct {
    Employee         // 匿名字段，继承自雇员
    expertise string // 工程师的专业领域
}

// 工程师的方法，打印工程师信息
func (e *Engineer) displayInfo() {
    fmt.Printf("Engineer: %s, 薪水: %.2f, 职位: %s\n", e.name, e.salary, e.expertise)
}

// 工程师特有的方法，展示技能
func (e *Engineer) demonstrateSkills() {
    fmt.Printf("%s 专业技能： %s.\n", e.name, e.expertise)
}

func main() {
    // 创建基类对象：雇员
    emp := Employee{"Tom", 50000}
    emp.displayInfo() // 输出：Employee: Tom, 薪水: 50000

    // 创建子类对象：经理
    mgr := Manager{Employee{"Jack", 80000}, "Engineering"}
    mgr.displayInfo() // 输出：Manager: Jack, 薪水: 80000, 部门: Engineering
    mgr.manageTeam()  // 输出：Jack 管理的部门.

    // 创建子类对象：工程师
    eng := Engineer{Employee{"Charlie", 60000}, "Software Development"}
    eng.displayInfo()       // 输出：Engineer: Charlie, 薪水: 60000, 职位: Software Development
    eng.demonstrateSkills() // 输出：Charlie 专业技能： Software Development.
}

/*
jarry@jarrys-MacBook-Pro inheritance % go run InheritanceExample.go
Employee: Tom, 薪水: 50000.00
Manager: Jack, 薪水: 80000.00, 部门: Engineering
Jack 管理 Engineering 部门.
Engineer: Charlie, 薪水: 60000.00, 职位: Software Development
Charlie 专业技能： Software Development.
*/
