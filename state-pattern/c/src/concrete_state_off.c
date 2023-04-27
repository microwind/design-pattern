#include "func.h"

/// 具体的状态实现者

void concrete_state_off_on(Context *context)
{
  // 状态变为on后，状态类切换到ConcreteStateOn
  printf("\r\n ConcreteStateOff::on() [turn ON ok!]");
  context->set_state(context, (State *)concrete_state_on_constructor());
}

void concrete_state_off_off(Context *context)
{
  // 当前是off状态，再点击off只是提示，不切换状态类
  printf("\r\n ConcreteStateOff::off() [needn't switch, state is OFF.]");
}

ConcreteStateOff *concrete_state_off_constructor()
{
  // printf("\r\n proxy_off_constructor() [构建ConcreteStateOff]");
  State *state = (State *)malloc(sizeof(State));
  ConcreteStateOff *state_off = (ConcreteStateOff *)state;
  strcpy(state_off->name, "ConcreteStateOff");
  state_off->on = &concrete_state_off_on;
  state_off->off = &concrete_state_off_off;
  return state_off;
}