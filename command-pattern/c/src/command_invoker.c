#include "func.h"

/*
命令调用类，通过关联命令来实行命令的调用
在命令模式中，Invoker（调用者）是一个可选的组件，
它负责将Command对象传递给Receiver，
并调用Command对象的execute方法来执行命令。
Invoker在实现命令模式时可以有多种实现方式。
*/

void print_command_list(Command **list, int command_list_size)
{
  printf("\r\nThe current command_list:");
  for (int i = 0; i < command_list_size; i++)
  {
    printf("\r\n [i=%d, command->name=%s]", i, list[i]->name);
  }
}

// 把命令存储到调用者的命令列表
void invoker_take_order(CommandInvoker *invoker, Command *command)
{
  printf("\r\n CommandInvoker::take_order() [invoker->name=%s, command->name=%s, invoker->command_list_size=%d]", invoker->name, command->name, invoker->command_list_size);

  // 列表长度增加1位
  int new_command_list_size = invoker->command_list_size + 1;

  /* 如果采取柔性数组，则无需申请新空间和复制内容 */
  // 把原列表命令暂存下来
  Command **old_command_list = invoker->command_list;
  // 给命令列表申请新空间
  invoker->command_list = (Command **)calloc(new_command_list_size, sizeof(Command *));
  // 复制原有命令到命令列表，如果采取柔性数组则无需复制
  for (int i = 0; i < invoker->command_list_size; i++)
  {
    invoker->command_list[i] = old_command_list[i];
  }
  free(old_command_list);

  // 把新的命令添加列表最后
  invoker->command_list[new_command_list_size - 1] = command;
  invoker->command_list_size = new_command_list_size;
  
  // 打印当前有多少命令
  // print_command_list(invoker->command_list, invoker->command_list_size);
}

// 统一执行全部命令
void invoker_execute_orders(CommandInvoker *invoker)
{
  printf("\r\n CommandInvoker::execute_orders() ");
  int command_list_size = invoker->command_list_size;
  Command **command_list = invoker->command_list;
  for (int i = 0; i < command_list_size; i++)
  {
    Command *command = command_list[i];
    command->execute(command);
    command_list[i] = NULL;
  }
  // 命令执行完后清除命令列表
  invoker->command_list_size = 0;
  invoker->command_list = (Command **)calloc(0, sizeof(Command *));
}

// 初始化CommandInvoker命令对象
CommandInvoker *command_invoker_constructor(char *name)
{
  printf("\r\n command_invoker_constructor() [name=%s]", name);
  CommandInvoker *invoker = (CommandInvoker *)malloc(sizeof(CommandInvoker));
  strncpy(invoker->name, name, 50);
  invoker->command_list_size = 0;
  invoker->take_order = &invoker_take_order;
  invoker->execute_orders = &invoker_execute_orders;
  return invoker;
}