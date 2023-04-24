#include <stdio.h>

// 代理模式就是用一个类来代理另一个类或几个类的功能，以便隔绝外部客户和内部真实类

// 定义接口
typedef struct Interface
{
    void (*method)(struct Interface *interface);
} Interface;

// 实现接口的具体类
typedef struct Concrete
{
    void (*method)(struct Concrete *interface);
} Concrete;

void real_method(struct Concrete *interface)
{
    printf("调用真实方法 real_method.\n");
}

// 代理类，继承接口，聚合具体类实例
typedef struct Proxy
{
    struct Interface *real_subject;
} Proxy;

// 代理类方法实现，通过聚合的具体类实例来调用具体类的方法
void proxy_method(struct Interface *interface)
{
    struct Proxy *p = (struct Proxy *)interface;
    p->real_subject->method((struct Interface *)p);
}

int main()
{
    // 创建具体类实例
    struct Concrete real_subject = {
        .method = &real_method,
    };

    // 创建代理类实例并聚合具体类实例
    struct Proxy proxy_instance = {
        .real_subject = (struct Interface *)&real_subject,
    };

    // 将代理类的方法指针指向代理类的方法实现
    struct Interface proxy_interface = {
        .method = &proxy_method,
    };

    // 通过代理类的接口调用具体类方法
    proxy_interface.method((struct Interface *)&proxy_instance);

    return 0;
}
