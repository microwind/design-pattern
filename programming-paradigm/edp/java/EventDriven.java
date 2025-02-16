import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
/*
一个简单的事件驱动系统，包含事件的注册、触发和移除功能。不同语言的实现方式有所不同，但核心逻辑是一致的：
事件管理器：负责管理事件及其对应的回调函数列表。
注册事件：将回调函数添加到对应事件的列表中。
触发事件：遍历对应事件的回调函数列表并依次调用。
移除事件：从对应事件的回调函数列表中移除指定的回调函数。
*/
// 事件管理器类
class EventManager {
  // 存储事件及其对应的回调函数列表
  private Map<Integer, List<Callback>> events;

  // 构造函数，初始化事件映射
  public EventManager() {
    events = new HashMap<>();
  }

  // 注册事件监听器
  public void on(int eventName, Callback callback) {
    events.computeIfAbsent(eventName, k -> new ArrayList<>()).add(callback);
  }

  // 触发事件
  public void emit(int eventName, String message) {
    List<Callback> callbacks = events.get(eventName);
    if (callbacks != null) {
      for (Callback callback : callbacks) {
        callback.handleMessage(message);
      }
    }
  }

  // 移除事件监听器
  public void off(int eventName, Callback callback) {
    List<Callback> callbacks = events.get(eventName);
    if (callbacks != null) {
      callbacks.remove(callback);
    }
  }
}

// 回调函数接口
interface Callback {
  void handleMessage(String message);
}

// 事件处理类
class MessageHandler implements Callback {
  @Override
  public void handleMessage(String message) {
    System.out.printf("收到消息: %s\n", message);
  }
}

public class EventDriven {
  public static void main(String[] args) {
    EventManager eventManager = new EventManager();
    MessageHandler messageHandler = new MessageHandler();

    // 第一次测试：注册并触发事件
    System.out.println("第一次测试：");
    // 注册事件监听器
    eventManager.on(0, messageHandler);
    // 触发事件
    eventManager.emit(0, "第一次发送的消息");

    // 第二次测试：再次触发事件
    System.out.println("\n第二次测试：");
    eventManager.emit(0, "第二次发送的消息");

    // 第三次测试：移除监听器后重新注册并触发事件
    System.out.println("\n第三次测试：");
    // 移除事件监听器
    eventManager.off(0, messageHandler);
    // 重新注册事件监听器
    eventManager.on(0, messageHandler);
    // 触发事件
    eventManager.emit(0, "第三次发送的消息");
  }
}

/*
 * 
 * jarry@Mac java % java EventDriven.java
 * 第一次测试：
 * 收到消息: 第一次发送的消息
 * 
 * 第二次测试：
 * 收到消息: 第二次发送的消息
 * 
 * 第三次测试：
 * 收到消息: 第三次发送的消息
 */