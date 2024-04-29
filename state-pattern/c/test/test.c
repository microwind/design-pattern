#include "../src/func.h"

int main(void)
{
  printf("test start:\r\n");
  /**
   * 状态模式就是对象Context在不同行为下有不同的状态，当前只有一种状态。
   * 通过行为的改变，状态也随之自动发生了改变。
   * 策略模式与状态模式类似，但策略模式是可以重新设置策略，而状态则通过行为来切换状态。
   */

  Context *context = context_constructor();
  // 初始状态是off
  context->set_state(context, (State *)concrete_state_off_constructor());
  // turn on
  context->turn_on(context);
  // 再次turn on
  context->turn_on(context);
  // turn off
  context->turn_off(context);
  // 再次turn off
  context->turn_off(context);
  printf("\r\n context.state: %s", context->get_state(context)->name);
}

// jarry@jarrys-MacBook-Pro c % gcc test/test.c ./src/*.c
// jarry@jarrys-MacBook-Pro c % ./a.out
/**
test start:

 context_constructor() [构建Context]
 Context::set_state() [state = ConcreteStateOff]
 ConcreteStateOff::on() [turn ON ok!]
 Context::set_state() [state = ConcreteStateOn]
 ConcreteStateOn::on() [needn't switch, state is ON.]
 ConcreteStateOn::off() [turn OFF ok!]
 Context::set_state() [state = ConcreteStateOff]
 ConcreteStateOff::off() [needn't switch, state is OFF.]
 context.state: ConcreteStateOff%   
 */