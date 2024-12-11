# 响应式编程概述

响应式编程(Reactive Programming, RP)，是一种面向数据流和变化传播的编程范式，它强调通过异步和非阻塞的方式处理数据流。它使程序能够以声明性的方式描述动态行为和交互，并自动处理变化带来的复杂性。

## JS代码示例

```js
let data = 0

// 订阅函数
function subscribe(callback) {
  callback(data)
}

// 修改数据并通知订阅者
function updateData(newValue) {
  data = newValue

  // 触发响应函数，数据自动更新
  subscribe((value) => {
    value += 10
    console.log('Data updated:', value)
  })
}

// 进行初始订阅
subscribe((value) => {
  console.log('Initial data:', value)
})

// 模拟数据更新
updateData(10)
updateData(20)
```

## Java代码示例
```java
/**
 * 以观察者模式为例子说明响应式编程。
 * 观察者一旦订阅主题后，消息发布以后，观察者自动更新通知。
 * 这就是通过数据的改变来触发数据流程。
 */
import java.util.*;

interface Observer {
    void update(String message);
}

class MyObserver implements Observer {
    String name = "MyObserver";

    MyObserver(String name) {
        this.name = name;
    }

    @Override
    public void update(String message) {
        System.out.println(this.name + " 接到新消息: " + message);
    }
}

class Subject {
    String name = "Subject";
    private List<Observer> observers = new ArrayList<Observer>();

    Subject(String name) {
        this.name = name;
    }

    public void addObserver(Observer observer) {
        this.observers.add(observer);
    }

    public void removeObserver(Observer observer) {
        this.observers.remove(observer);
    }

    public void notify(String message) {
        this.observers.forEach((observer) -> {
            observer.update(message);
        });
    }
}

public class ReactiveExample {
    // 测试验证
    public static void main(String[] args) {
        // 创建主题对象和观察者对象
        Subject subject1 = new Subject("Subject1");
        Observer observer1 = new MyObserver("Observer1");
        Observer observer2 = new MyObserver("Observer2");

        // 注册观察者到主题
        subject1.addObserver(observer1);
        subject1.addObserver(observer2);

        // 主题发布数据时，绑定的观察者自动更新
        subject1.notify("发布消息");

        // 移除掉观察者
        subject1.removeObserver(observer1);
        // 再次发布消息
        subject1.notify("再次发布消息");
    }
}
```
