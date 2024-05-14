/*
聚合是一个对象（整体）包含或引用其他对象（部分），但这些部分对象在逻辑上可以独立于整体对象。
本示例：
- 聚合关系：Department类聚合了Employee。Department类包含一个Employee列表，但这些员工的生命周期不依赖于部门。如果部门被销毁，员工对象仍然可以继续存在。这种关系是典型的聚合关系。
- 松散耦合：聚合允许整体和部分对象之间具有较低的耦合度，这使得系统更易于维护和扩展。部分对象可以独立存在，整体对象只是引用它们。
- 部分-整体关系：部门包含员工，但员工可以属于多个部门，也可以独立存在。这种关系使得代码更加灵活，并允许部分对象在整体对象之外被重用。
*/

// 定义一个员工类
class Employee {
  private name: string

  constructor(name: string) {
    this.name = name // 初始化员工名字
  }

  getName(): string {
    return this.name // 获取员工名字
  }
}

// 定义一个部门类
class Department {
  private departmentName: string // 部门名称
  private employees: Employee[] // 部门包含的员工列表

  constructor(departmentName: string) {
    this.departmentName = departmentName // 初始化部门名称
    this.employees = [] // 初始化员工列表
  }

  // 添加员工到部门
  addEmployee(employee: Employee): void {
    this.employees.push(employee) // 将员工添加到列表
  }

  // 获取部门的所有员工名字
  listEmployees(): void {
    console.log('Employees in ' + this.departmentName + ':')
    this.employees.forEach((employee) => {
      console.log(employee.getName()) // 输出员工名字
    })
  }
}

// 测试验证
// 创建几个员工对象
let tom: Employee = new Employee('Tom')
let jerry: Employee = new Employee('Jerry')

// 创建一个部门，并将员工添加到部门
let itDepartment: Department | null = new Department('IT Resources')
itDepartment.addEmployee(tom)
itDepartment.addEmployee(jerry)

// 列出部门中的员工
itDepartment.listEmployees() // 输出：Employees in IT Resources: Tom, Jerry

// 即使部门被销毁，员工对象仍然可以继续存在
itDepartment = null // 删除部门对象

console.log('Employee Tom still exists: ' + tom.getName()) // 输出：Tom

/**
jarry@jarrys-MacBook-Pro aggregation % ts-node AggregationExample.ts
Employees in IT Resources:
Tom
Jerry
Employee Tom still exists: Tom
jarry@jarrys-MacBook-Pro aggregation % 
 */
