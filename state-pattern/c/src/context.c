#include "func.h"

// 具体执行实体类，内部关联状态
State *context_get_state(Context *context)
{
  return context->state;
}

void context_set_state(Context *context, State *state)
{
  printf("\r\n Context::set_state() [state = %s]", state->name);
  context->state = state;
}

void context_turn_on(Context *context)
{
  context->state->on(context);
}

void context_turn_off(Context *context)
{
  context->state->off(context);
}

Context *context_constructor()
{
  printf("\r\n context_constructor() [构建Context]");
  Context *context = (Context *)malloc(sizeof(Context));
  context->get_state = &context_get_state;
  context->set_state = &context_set_state;
  context->turn_on = &context_turn_on;
  context->turn_off = &context_turn_off;
  return context;
}