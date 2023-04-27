#include "func.h"

// 具体的状态实现者
// 策略模式与状态模式都是将策略/状态绑定到执行对象(Context)上
// 不同的是策略模式是客户可设定策略，而状态则是通过状态动作来实现改变
void concrete_state_on_on(Context *context)
{
  // 当前是on状态，再点击on只是提示，不切换状态类
  printf("\r\n ConcreteStateOn::on() [needn't switch, state is ON.]");
}

void concrete_state_on_off(Context *context)
{
  // 状态变为off后，状态类切换到ConcreteStateOff
  printf("\r\n ConcreteStateOn::off() [turn OFF ok!]");
  context->set_state(context, (State *)concrete_state_off_constructor());
}

ConcreteStateOn *concrete_state_on_constructor()
{
  // printf("\r\n proxy_off_constructor() [构建ConcreteStateOff]");
  State *state = (State *)malloc(sizeof(State));
  ConcreteStateOn *state_on = (ConcreteStateOn *)state;
  strcpy(state_on->name, "ConcreteStateOn");
  state_on->on = &concrete_state_on_on;
  state_on->off = &concrete_state_on_off;
  return state_on;
}
