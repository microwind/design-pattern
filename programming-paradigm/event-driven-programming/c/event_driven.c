#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char *event_name;
    Callback callbacks[MAX_CALLBACKS];
    int callback_count;
} Event;

// 事件管理器结构体
typedef struct
{
    Event events[MAX_EVENTS];
    int event_count;
} EventManager;

// 初始化事件管理器
void init_event_manager(EventManager *manager)
{
    manager->event_count = 0;
}

// 查找事件索引
int find_event_index(EventManager *manager, const char *event_name)
{
    for (int i = 0; i < manager->event_count; i++)
    {
        if (strcmp(manager->events[i].event_name, event_name) == 0)
        {
            return i;
        }
    }
    return -1;
}

// 注册事件监听器
void on(EventManager *manager, const char *event_name, Callback callback)
{
    int index = find_event_index(manager, event_name);
    if (index == -1)
    {
        if (manager->event_count >= MAX_EVENTS)
            return;
        index = manager->event_count++;
        manager->events[index].event_name = strdup(event_name);
        manager->events[index].callback_count = 0;
    }
    if (manager->events[index].callback_count < MAX_CALLBACKS)
    {
        manager->events[index].callbacks[manager->events[index].callback_count++] = callback;
    }
}

// 触发事件
void emit(EventManager *manager, const char *event_name, const char *message)
{
    int index = find_event_index(manager, event_name);
    if (index != -1)
    {
        for (int i = 0; i < manager->events[index].callback_count; i++)
        {
            manager->events[index].callbacks[i](message);
        }
    }
}

// 移除事件监听器
void off(EventManager *manager, const char *event_name, Callback callback)
{
    int index = find_event_index(manager, event_name);
    if (index != -1)
    {
        for (int i = 0; i < manager->events[index].callback_count; i++)
        {
            if (manager->events[index].callbacks[i] == callback)
            {
                for (int j = i; j < manager->events[index].callback_count - 1; j++)
                {
                    manager->events[index].callbacks[j] = manager->events[index].callbacks[j + 1];
                }
                manager->events[index].callback_count--;
                break;
            }
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
    on(&eventManager, "event1", handleMessage);
    emit(&eventManager, "event1", "第一次发送的消息");

    // 第二次测试：再次触发事件
    printf("\n第二次测试：\n");
    emit(&eventManager, "event1", "第二次发送的消息");

    // 第三次测试：移除监听器后重新注册并触发事件
    printf("\n第三次测试：\n");
    off(&eventManager, "event1", handleMessage);
    on(&eventManager, "event1", handleMessage);
    emit(&eventManager, "event1", "第三次发送的消息");

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