/**
 * 以观察者模式为例子说明响应式编程。
 * 观察者一旦订阅主题后，消息发布以后，观察者自动更新通知。
 * 这就是通过数据的改变来触发数据流程。
 */

// 定义主题对象
class Subject {

  constructor(name) {
    this.name = name || 'Subject';
    this.observers = [];
  }

  // 添加观察者
  addObserver(observer) {
    this.observers.push(observer);
  }

  // 删除观察者
  removeObserver(observer) {
    const index = this.observers.indexOf(observer);
    if (index !== -1) {
      this.observers.splice(index, 1);
    }
  }

  // 通知观察者
  notify(data) {
    this.observers.forEach(observer => observer.update(data));
  }
}

// 定义观察者对象
class Observer {
  constructor(name) {
    this.name = name || 'Observer';
  }

  // 更新函数
  update(data) {
    console.log(`${this.name} 收到数据更新: ${data}`);
  }
}

// 测试验证
(function () {
  // 创建主题对象和观察者对象
  const subject1 = new Subject('Subject1');
  const observer1 = new Observer('Observer1');
  const observer2 = new Observer('Observer2');

  // 注册观察者到主题
  subject1.addObserver(observer1);
  subject1.addObserver(observer2);

  // 主题发布数据时，绑定的观察者自动更新
  subject1.notify('发布消息');

  // 移除掉观察者
  subject1.removeObserver(observer1);
  // 再次发布消息
  subject1.notify('再次发布消息');
})();

/**
jarry@jarrys-MacBook-Pro js % node ReactiveExample.js
Observer1 收到数据更新: 发布消息
Observer2 收到数据更新: 发布消息
Observer2 收到数据更新: 再次发布消息
 */