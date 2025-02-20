/**
 * 以观察者模式为例子说明响应式编程。
 * 观察者一旦订阅主题后，消息发布以后，观察者自动更新通知。
 * 这就是通过数据的改变来触发数据流程。
 */
use std::rc::Rc;

// 定义观察者 trait
trait Observer {
    fn update(&self, message: &str);
}

// 实现 MyObserver 结构体
struct MyObserver {
    name: String,
}

impl MyObserver {
    fn new(name: &str) -> Rc<dyn Observer> {
        Rc::new(MyObserver {
            name: name.to_string(),
        })
    }
}

impl Observer for MyObserver {
    fn update(&self, message: &str) {
        println!("{} 接到新消息: {}", self.name, message);
    }
}

// 实现 Subject 结构体（去掉了未使用的 `name` 字段）
struct Subject {
    observers: Vec<Rc<dyn Observer>>,
}

impl Subject {
    fn new() -> Self {
        Subject {
            observers: Vec::new(),
        }
    }

    // 添加观察者
    fn add_observer(&mut self, observer: Rc<dyn Observer>) {
        self.observers.push(observer);
    }

    // 移除观察者
    fn remove_observer(&mut self, observer: Rc<dyn Observer>) {
        if let Some(index) = self.observers.iter().position(|x| Rc::ptr_eq(x, &observer)) {
            self.observers.remove(index);
        }
    }

    // 通知所有观察者
    fn notify(&self, message: &str) {
        for observer in &self.observers {
            observer.update(message);
        }
    }
}

fn main() {
    // 测试验证
    // 创建主题对象和观察者对象
    let mut subject1 = Subject::new();
    let observer1 = MyObserver::new("Observer1");
    let observer2 = MyObserver::new("Observer2");

    // 注册观察者到主题
    subject1.add_observer(Rc::clone(&observer1));
    subject1.add_observer(Rc::clone(&observer2));

    // 主题发布数据时，绑定的观察者自动更新
    subject1.notify("发布消息");

    // 移除掉观察者
    subject1.remove_observer(observer1);
    // 再次发布消息
    subject1.notify("再次发布消息");
}

/*
jarry@Mac rust % rustc reactive.rs
jarry@Mac rust % ./reactive
Observer1 接到新消息: 发布消息
Observer2 接到新消息: 发布消息
Observer2 接到新消息: 再次发布消息
 */
