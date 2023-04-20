#include "func.h"

// 每次创建一个新备忘录来保存状态
Memento *originator_save_memento(Originator *originator)
{
  printf("\r\n Originator::save_memento() [state = %s]", originator->state);
  Memento *memento = memento_constructor("Memento", originator->state);
  return memento;
}

// 从备忘录中恢复状态
void originator_restore_memento(Originator *originator, Memento *memento)
{
  strncpy(originator->state, memento->get_state(memento), 50);
}

void originator_set_state(Originator *originator, char *state)
{
  strncpy(originator->state, state, 50);
}

char *originator_get_state(Originator *originator)
{
  return originator->state;
}

// 发起人(Originator)负责生成状态快照，即利用一个新备忘录对象将自己的内部状态存储起来
Originator *originator_constructor()
{
  printf("\r\n originator_constructor() [构建通用聊天室]");
  Originator *originator = (Originator *)malloc(sizeof(Originator));
  originator->save_memento = &originator_save_memento;
  originator->restore_memento = &originator_restore_memento;
  originator->set_state = &originator_set_state;
  originator->get_state = &originator_get_state;
  return originator;
}