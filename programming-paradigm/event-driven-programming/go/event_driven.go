package main

import "fmt"

/*
一个简单的事件驱动系统，包含事件的注册、触发和移除功能。不同语言的实现方式有所不同，但核心逻辑是一致的：
事件管理器：负责管理事件及其对应的回调函数列表。
注册事件：将回调函数添加到对应事件的列表中。
触发事件：遍历对应事件的回调函数列表并依次调用。
移除事件：从对应事件的回调函数列表中移除指定的回调函数。
*/

// 事件管理器结构体
type EventManager struct {
  events map[string][]func(string)
}

// 初始化事件管理器
func NewEventManager() *EventManager {
  return &EventManager{
    events: make(map[string][]func(string)),
  }
}

// 注册事件监听器
func (em *EventManager) On(eventName string, callback func(string)) {
  if _, exists := em.events[eventName]; !exists {
    em.events[eventName] = make([]func(string), 0)
  }
  em.events[eventName] = append(em.events[eventName], callback)
}

// 触发事件
func (em *EventManager) Emit(eventName string, message string) {
  if callbacks, exists := em.events[eventName]; exists {
    for _, callback := range callbacks {
      callback(message)
    }
  }
}

// 移除事件监听器
func (em *EventManager) Off(eventName string, callback func(string)) {
  if callbacks, exists := em.events[eventName]; exists {
    for i, cb := range callbacks {
      // 通过比较函数指针地址来确定是否是同一个回调函数
      if fmt.Sprintf("%p", cb) == fmt.Sprintf("%p", callback) {
        em.events[eventName] = append(callbacks[:i], callbacks[i+1:]...)
        break
      }
    }
  }
}

// 事件处理函数
func handleMessage(message string) {
  fmt.Printf("收到消息: %s\n", message)
}

func main() {
  eventManager := NewEventManager()

  // 第一次测试：注册并触发事件
  fmt.Println("第一次测试：")
  eventManager.On("event1", handleMessage)
  eventManager.Emit("event1", "第一次发送的消息")

  // 第二次测试：再次触发事件
  fmt.Println("\n第二次测试：")
  eventManager.Emit("event1", "第二次发送的消息")

  // 第三次测试：移除监听器后重新注册并触发事件
  fmt.Println("\n第三次测试：")
  eventManager.Off("event1", handleMessage)
  eventManager.On("event1", handleMessage)
  eventManager.Emit("event1", "第三次发送的消息")
}

/*
jarry@Mac go % go run event_driven.go
第一次测试：
收到消息: 第一次发送的消息

第二次测试：
收到消息: 第二次发送的消息

第三次测试：
收到消息: 第三次发送的消息
*/
