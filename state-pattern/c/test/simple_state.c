#include <stdio.h>
// 状态模式将对象的行为封装在不同的状态对象中
// 将对象的状态从对象中分离出来，客户端无需关心对象的当前状态和状态的转换。
typedef struct Context Context;

// 执行对象
struct Context
{
    // 设置状态
    char name[50];
    void (*change_state)(Context *context);
};

// 定义不同状态函数
void state_A_change_state(Context *context);
void state_B_change_state(Context *context);
void state_C_change_state(Context *context);

void state_A_change_state(Context *context)
{
    printf("\r\n state_A_change_state() [context=%s change to=%s]", context->name, "state_B");
    // 切换到状态 B
    context->change_state = state_B_change_state;
}

void state_B_change_state(Context *context)
{
    printf("\r\n state_B_change_state() [context=%s change to=%s]", context->name, "state_C");
    // 切换到状态 C
    context->change_state = state_C_change_state;
}

void state_C_change_state(Context *context)
{
    printf("\r\n state_C_change_state() [context=%s change to=%s]", context->name, "state_A");
    // 切换到状态 A
    context->change_state = state_A_change_state;
}

int main()
{
    printf("test start:\r\n");
    Context context = {
        .name = "Context01",
        .change_state = state_A_change_state};

    // 当前只有一种状态
    for (int i = 0; i < 5; i++)
    {
        context.change_state(&context);
    }

    return 0;
}

/**
jarry@jarrys-MacBook-Pro c % gcc test/simple_state.c
jarry@jarrys-MacBook-Pro c % ./a.out                
test start:

 state_A_change_state() [context=Context01 change to=state_B]
 state_B_change_state() [context=Context01 change to=state_C]
 state_C_change_state() [context=Context01 change to=state_A]
 state_A_change_state() [context=Context01 change to=state_B]
 state_B_change_state() [context=Context01 change to=state_C]%  
*/