/*
接口是一种抽象方法的集合，与类属于不同的概念。类描述对象的属性和方法，接口则定义类需要实现的方法。
接口和抽象类有点像，都是一种抽象类型，但两者很大不同。
抽象类是对一种事物整体的抽象，即对类抽象，包括属性、行为等，子类和抽象类是一种"is-a"的关系。
而接口是对行为的抽象，是对类局部（行为）进行抽象，接口表示一种"can-do"的关系。
抽象类作为子类的父类，它是一种模板式设计。接口是一种行为规范，它是一种辐射式设计。

本示例：
- Door接口定义了门的基本行为：打开和关闭。
- Alarm接口定义了报警器的行为：触发报警。
- AbstractAlarm抽象类实现了Alarm接口，提供了一个空的trigger()方法，具体的报警器类可以通过覆盖这个方法来实现具体的报警逻辑。
- SecurityDoor类实现了Door接口，并继承了AbstractAlarm类，表示一种既可以打开和关闭的门，又具有报警功能。
通过这种设计，我们实现了门和报警器的分离，并且可以轻松地扩展系统以支持其他类型的门和报警器，而不需要修改现有的代码。
 */

// 定义门接口
interface Door {
  open(): void // 打开门

  close(): void // 关闭门
}

// 定义报警器接口
interface Alarm {
  trigger(): void // 触发报警
}

// 抽象类：AbstractAlarm，实现了报警器接口
abstract class AbstractAlarm implements Alarm {
  trigger() {
    // 空方法体，具体报警器实现时需覆盖该方法
  }
}

// 实现安全门类，继承报警抽象类，同时实现了门接口和报警器接口
class SecurityDoor extends AbstractAlarm implements Door {
  open() {
    console.log('安全门打开')
  }

  close() {
    console.log('安全门关闭')
  }

  // 覆盖父类的trigger方法，实现具体的报警逻辑
  trigger() {
    console.log('警报触发! 有一条安全告警。')
  }
}

// 测试验证
let securityDoor: SecurityDoor = new SecurityDoor()

// 打开门
securityDoor.open()

// 关闭门
securityDoor.close()

// 触发报警
securityDoor.trigger()
