#include "func.h"

void caretaker_add(Caretaker *caretaker, Memento *memento)
{
  printf("\r\n Caretaker::add() [memento = %s]", memento->name);
  caretaker->memento_length += 1;
  Memento **new_memento_list = (Memento **)calloc(caretaker->memento_length, sizeof(Memento));
  // 复制原有数组，并追加新内容到新数组
  for (int i = 0; i < caretaker->memento_length - 1; i++)
  {
    new_memento_list[i] = caretaker->memento_list[i];
  }
  new_memento_list[caretaker->memento_length - 1] = memento;
  free(caretaker->memento_list);
  // 指向新数组
  caretaker->memento_list = new_memento_list;
}

Memento *caretaker_get(Caretaker *caretaker, int index)
{
  return caretaker->memento_list[index];
}

// 负责人(Caretaker)角色，只负责保存备忘录记录，不能修改备忘录对象的内容
Caretaker *caretaker_constructor()
{
  printf("\r\n caretaker_constructor() [构建Caretaker]");
  Caretaker *caretaker = (Caretaker *)malloc(sizeof(Caretaker));
  caretaker->add = &caretaker_add;
  caretaker->get = &caretaker_get;
  return caretaker;
}