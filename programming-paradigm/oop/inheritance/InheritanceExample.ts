/*
继承即子类继承父类的特征和行为，使得子类对象（实例）具有父类的属性和方法。
这个例子展示了继承的多种应用，包括代码复用、层次结构和多态。
本示例：
- 基类和子类：Employee是基类，Manager和Engineer是子类。子类继承了基类的属性和方法。
- 代码复用：子类通过继承自动获得了基类的属性和方法，这减少了代码重复。
- 方法重写：子类重写了基类的displayInfo方法，提供了更具体的信息。
- 多态：通过父类引用子类对象，代码可以灵活地使用不同的子类，而无需明确指定子类的类型。这允许代码在运行时根据实际对象类型选择适当的行为。 
*/

// 定义基类：雇员
class Employee {
  name: string // 雇员的名字
  salary: number // 雇员的工资

  constructor(name: string, salary: number) {
    this.name = name // 初始化雇员名字
    this.salary = salary // 初始化雇员工资
  }

  // 基类中的方法，打印雇员信息
  displayInfo() {
    console.log(`Employee: ${this.name}, 薪水: ${this.salary}`)
  }
}

// 子类：经理，继承自雇员
class Manager extends Employee {
  department: string // 经理负责的部门

  constructor(name: string, salary: number, department: string) {
    super(name, salary) // 调用父类的构造方法
    this.department = department // 初始化部门
  }

  // 覆写父类的方法，打印经理信息
  displayInfo() {
    console.log(
      `Manager: ${this.name}, 薪水: ${this.salary}, 部门: ${this.department}`
    )
  }

  // 经理特有的方法，管理团队
  manageTeam() {
    console.log(`${this.name} 管理 ${this.department} 部门.`)
  }
}

// 子类：工程师，继承自雇员
class Engineer extends Employee {
  expertise: string // 工程师的专业领域

  constructor(name: string, salary: number, expertise: string) {
    super(name, salary) // 调用父类的构造方法
    this.expertise = expertise // 初始化专业领域
  }

  // 覆写父类的方法，打印工程师信息
  displayInfo() {
    console.log(
      `Engineer: ${this.name}, 薪水: ${this.salary}, 职位: ${this.expertise}`
    )
  }

  // 工程师特有的方法，展示技能
  demonstrateSkills() {
    console.log(`${this.name} 专业技能： ${this.expertise}.`)
  }
}

// 创建基类对象：雇员
let emp: Employee = new Employee('Tom', 50000)
emp.displayInfo() // 输出：Employee: Tom, 薪水: 50000

// 创建子类对象：经理
let mgr: Manager = new Manager('Jack', 80000, 'Engineering')
mgr.displayInfo() // 输出：Manager: Jack, 薪水: 80000, 部门: Engineering
mgr.manageTeam() // 输出：Jack 管理的部门.

// 创建子类对象：工程师
let eng: Engineer = new Engineer('Charlie', 60000, 'Software Development')
eng.displayInfo() // 输出：Engineer: Charlie, 薪水: 60000, 职位: Software Development
eng.demonstrateSkills() // 输出：Charlie 专业技能： Software Development.

/**
jarry@jarrys-MacBook-Pro inheritance % ts-node InheritanceExample.ts
Employee: Tom, 薪水: 50000
Manager: Jack, 薪水: 80000, 部门: Engineering
Jack 管理 Engineering 部门.
Engineer: Charlie, 薪水: 60000, 职位: Software Development
Charlie 专业技能： Software Development.
 */