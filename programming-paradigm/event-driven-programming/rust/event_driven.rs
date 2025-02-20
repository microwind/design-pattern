use std::collections::HashMap;

/*
一个简单的事件驱动系统，包含事件的注册、触发和移除功能。不同语言的实现方式有所不同，但核心逻辑是一致的：
事件管理器：负责管理事件及其对应的回调函数列表。
注册事件：将回调函数添加到对应事件的列表中。
触发事件：遍历对应事件的回调函数列表并依次调用。
移除事件：从对应事件的回调函数列表中移除指定的回调函数。
*/

// 定义回调函数类型
type Callback = fn(&str);

// 事件管理器结构体
struct EventManager {
    events: HashMap<String, Vec<Callback>>,
}

impl EventManager {
    // 初始化事件管理器
    fn new() -> Self {
        EventManager {
            events: HashMap::new(),
        }
    }

    // 注册事件监听器
    fn on(&mut self, event_name: &str, callback: Callback) {
        self.events
            .entry(event_name.to_string())
            .or_insert(Vec::new())
            .push(callback);
    }

    // 触发事件
    fn emit(&self, event_name: &str, message: &str) {
        if let Some(callbacks) = self.events.get(event_name) {
            for callback in callbacks {
                callback(message);
            }
        }
    }

    // 移除事件监听器
    fn off(&mut self, event_name: &str, callback: Callback) {
        if let Some(callbacks) = self.events.get_mut(event_name) {
            callbacks.retain(|&cb| cb != callback);
        }
    }
}

// 事件处理函数
fn handle_message(message: &str) {
    println!("收到消息: {}", message);
}

fn main() {
    let mut event_manager = EventManager::new();

    // 第一次测试：注册并触发事件
    println!("第一次测试：");
    event_manager.on("event1", handle_message);
    event_manager.emit("event1", "第一次发送的消息");

    // 第二次测试：再次触发事件
    println!("\n第二次测试：");
    event_manager.emit("event1", "第二次发送的消息");

    // 第三次测试：移除监听器后重新注册并触发事件
    println!("\n第三次测试：");
    event_manager.off("event1", handle_message);
    event_manager.on("event1", handle_message);
    event_manager.emit("event1", "第三次发送的消息");
}

/*
jarry@Mac rust % rustc event_driven.rs
jarry@Mac rust % ./event_driven
第一次测试：
收到消息: 第一次发送的消息

第二次测试：
收到消息: 第二次发送的消息

第三次测试：
收到消息: 第三次发送的消息
*/
