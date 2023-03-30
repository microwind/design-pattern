#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 基础命令结构体
typedef struct Command
{
    char name[50];
    struct StockReceiver *stock_receiver;
    void (*set_stock_receiver)(struct Command *command, struct StockReceiver *);
    void (*execute)(struct Command *);
} Command;

// 接受者对象
typedef struct StockReceiver
{
    char name[50];
    int num;
    void (*buy)(struct StockReceiver *);
    void (*sell)(struct StockReceiver *);
} StockReceiver;
StockReceiver *stock_receiver_constructor(char *name, int num);

// 继承命令结构体
typedef struct BuyCommand
{
    char name[50];
    struct StockReceiver *stock_receiver;
    void (*set_stock_receiver)(struct BuyCommand *command, struct StockReceiver *);
    void (*execute)(struct Command *);
} BuyCommand;
BuyCommand *buy_command_constructor(char *name);

// 继承命令结构体
typedef struct SellCommand
{
    char name[50];
    struct StockReceiver *stock_receiver;
    void (*set_stock_receiver)(struct SellCommand *command, struct StockReceiver *);
    void (*execute)(struct Command *);
} SellCommand;
SellCommand *sell_command_constructor(char *name);

// 命令执行者
typedef struct CommandInvoker
{
    char name[50];
    void (*take_order)(struct CommandInvoker *invoker, Command *command);
    void (*execute_orders)(struct CommandInvoker *invoker);
    // 数组命令列表，记录待执行的命令对象
    struct Command **command_list;
    // 数组长度记录
    int command_list_size;
    // 若是柔性数组，则放在结构体最后，可以动态追加内容
    // struct Command *command_list[];
} CommandInvoker;
CommandInvoker *command_invoker_constructor(char *name);
