"""
一个简单的事件驱动系统，包含事件的注册、触发和移除功能。不同语言的实现方式有所不同，但核心逻辑是一致的：
事件管理器：负责管理事件及其对应的回调函数列表。
注册事件：将回调函数添加到对应事件的列表中。
触发事件：遍历对应事件的回调函数列表并依次调用。
移除事件：从对应事件的回调函数列表中移除指定的回调函数。
"""
# 事件管理器类
class EventManager:
    def __init__(self):
        # 用于存储事件及其对应的回调函数列表
        self.events = {}

    # 注册事件监听器
    def on(self, event_name, callback):
        if event_name not in self.events:
            self.events[event_name] = []
        self.events[event_name].append(callback)

    # 触发事件
    def emit(self, event_name, message):
        if event_name in self.events:
            for callback in self.events[event_name]:
                callback(message)

    # 移除事件监听器
    def off(self, event_name, callback):
        if event_name in self.events:
            if callback in self.events[event_name]:
                self.events[event_name].remove(callback)

# 事件处理函数


def handleMessage(message):
    print(f"收到消息: {message}")


if __name__ == "__main__":
    eventManager = EventManager()

    # 第一次测试：注册并触发事件
    print("第一次测试：")
    # 注册事件监听器
    eventManager.on(0, handleMessage)
    # 触发事件
    eventManager.emit(0, "第一次发送的消息")

    # 第二次测试：再次触发事件
    print("\n第二次测试：")
    eventManager.emit(0, "第二次发送的消息")

    # 第三次测试：移除监听器后重新注册并触发事件
    print("\n第三次测试：")
    # 移除事件监听器
    eventManager.off(0, handleMessage)
    # 重新注册事件监听器
    eventManager.on(0, handleMessage)
    # 触发事件
    eventManager.emit(0, "第三次发送的消息")

"""
jarry@Mac python % python event_driven.py 
第一次测试：
收到消息: 第一次发送的消息

第二次测试：
收到消息: 第二次发送的消息

第三次测试：
收到消息: 第三次发送的消息
"""