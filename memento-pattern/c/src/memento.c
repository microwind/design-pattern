#include "func.h"

char *get_state(Memento *m)
{
  return m->state;
}

void set_state(Memento *m, char *state)
{
  strncpy(m->state, state, 50);
}

// 备忘录(Memento)角色，负责存储发起人传入的状态
Memento *memento_constructor(char *name, char *state)
{
  printf("\r\n memento_constructor() [构建Memento name=%s state=%s]", name, state);
  Memento *memento = (Memento *)malloc(sizeof(Memento));
  strncpy(memento->name, name, 50);
  strncpy(memento->state, state, 50);
  memento->get_state = &get_state;
  memento->set_state = &set_state;
  return memento;
}