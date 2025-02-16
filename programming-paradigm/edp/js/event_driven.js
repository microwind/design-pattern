/*
一个简单的事件驱动系统，包含事件的注册、触发和移除功能。不同语言的实现方式有所不同，但核心逻辑是一致的：
事件管理器：负责管理事件及其对应的回调函数列表。
注册事件：将回调函数添加到对应事件的列表中。
触发事件：遍历对应事件的回调函数列表并依次调用。
移除事件：从对应事件的回调函数列表中移除指定的回调函数。
*/
// 自定义事件管理器类
class EventManager {
  constructor() {
    // 用于存储事件及其对应的回调函数列表
    this.events = {};
  }

  // 注册事件监听器的方法
  on(eventName, callback) {
    if (!this.events[eventName]) {
      // 如果该事件还没有对应的回调函数列表，就初始化一个空数组
      this.events[eventName] = [];
    }
    // 将回调函数添加到对应事件的回调列表中
    this.events[eventName].push(callback);
  }

  // 触发事件的方法
  emit(eventName, ...args) {
    if (this.events[eventName]) {
      // 遍历该事件对应的所有回调函数
      this.events[eventName].forEach(callback => {
        // 依次调用每个回调函数，并传入参数
        callback(...args);
      });
    }
  }

  // 移除事件监听器的方法
  off(eventName, callback) {
    if (this.events[eventName]) {
      // 过滤掉指定的回调函数，保留其他回调函数
      this.events[eventName] = this.events[eventName].filter(cb => cb !== callback);
    }
  }
}

// 使用示例
// 创建事件管理器实例
const eventManager = new EventManager();

// 定义事件处理函数
function handleMessage(message) {
  console.log(`收到消息: ${message}`);
}

(function test(params) {
  // 第一次测试：注册并触发事件
  console.log("第一次测试：");
  // 注册事件监听器
  eventManager.on('message', handleMessage);
  // 触发事件
  eventManager.emit('message', '第一次发送的消息');

  // 第二次测试：再次触发事件
  console.log("\n第二次测试：");
  eventManager.emit('message', '第二次发送的消息');

  // 第三次测试：移除监听器后重新注册并触发事件
  console.log("\n第三次测试：");
  // 移除事件监听器
  eventManager.off('message', handleMessage);
  // 重新注册事件监听器
  eventManager.on('message', handleMessage);
  // 触发事件
  eventManager.emit('message', '第三次发送的消息');
})()

/*
jarry@Mac js % node event_driven.js
第一次测试：
收到消息: 第一次发送的消息

第二次测试：
收到消息: 第二次发送的消息

第三次测试：
收到消息: 第三次发送的消息
*/