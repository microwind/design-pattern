#include <stdio.h>
#include <stdlib.h>
/*
一个简单的事件驱动系统，包含事件的注册、触发和移除功能。不同语言的实现方式有所不同，但核心逻辑是一致的：
事件管理器：负责管理事件及其对应的回调函数列表。
注册事件：将回调函数添加到对应事件的列表中。
触发事件：遍历对应事件的回调函数列表并依次调用。
移除事件：从对应事件的回调函数列表中移除指定的回调函数。
*/
// 定义最大事件数量
#define MAX_EVENTS 100
// 定义每个事件的最大回调函数数量
#define MAX_CALLBACKS 10

// 定义回调函数类型
typedef void (*Callback)(const char *);

// 事件结构体
typedef struct
{
    Callback callbacks[MAX_CALLBACKS];
    int callback_count;
} Event;

// 事件管理器结构体
typedef struct
{
    Event events[MAX_EVENTS];
    // 事件名称假设为简单的整数索引
    int event_count;
} EventManager;

// 初始化事件管理器
void init_event_manager(EventManager *manager)
{
    manager->event_count = 0;
    for (int i = 0; i < MAX_EVENTS; i++)
    {
        manager->events[i].callback_count = 0;
    }
}

// 注册事件监听器
void on(EventManager *manager, int event_name, Callback callback)
{
    if (manager->events[event_name].callback_count < MAX_CALLBACKS)
    {
        manager->events[event_name].callbacks[manager->events[event_name].callback_count++] = callback;
    }
}

// 触发事件
void emit(EventManager *manager, int event_name, const char *message)
{
    for (int i = 0; i < manager->events[event_name].callback_count; i++)
    {
        manager->events[event_name].callbacks[i](message);
    }
}

// 移除事件监听器
void off(EventManager *manager, int event_name, Callback callback)
{
    for (int i = 0; i < manager->events[event_name].callback_count; i++)
    {
        if (manager->events[event_name].callbacks[i] == callback)
        {
            for (int j = i; j < manager->events[event_name].callback_count - 1; j++)
            {
                manager->events[event_name].callbacks[j] = manager->events[event_name].callbacks[j + 1];
            }
            manager->events[event_name].callback_count--;
            break;
        }
    }
}

// 事件处理函数
void handleMessage(const char *message)
{
    printf("收到消息: %s\n", message);
}

int main()
{
    EventManager eventManager;
    init_event_manager(&eventManager);

    // 第一次测试：注册并触发事件
    printf("第一次测试：\n");
    // 注册事件监听器
    on(&eventManager, 0, handleMessage);
    // 触发事件
    emit(&eventManager, 0, "第一次发送的消息");

    // 第二次测试：再次触发事件
    printf("\n第二次测试：\n");
    emit(&eventManager, 0, "第二次发送的消息");

    // 第三次测试：移除监听器后重新注册并触发事件
    printf("\n第三次测试：\n");
    // 移除事件监听器
    off(&eventManager, 0, handleMessage);
    // 重新注册事件监听器
    on(&eventManager, 0, handleMessage);
    // 触发事件
    emit(&eventManager, 0, "第三次发送的消息");

    return 0;
}

/*
jarry@Mac c % gcc event_driven.c
jarry@Mac c % ./a.out
第一次测试：
收到消息: 第一次发送的消息

第二次测试：
收到消息: 第二次发送的消息

第三次测试：
收到消息: 第三次发送的消息
*/