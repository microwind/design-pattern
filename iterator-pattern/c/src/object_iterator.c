#include "func.h"

bool has_next(Iterator *iter)
{
  if (iter->index < iter->object_list->length)
  {
    return true;
  }
  return false;
}

char *next(Iterator *iter)
{
  if (iter->has_next(iter))
  {
    // 返回数据对象提供的get方法，每访问一次下标增加1位
    char *item = iter->object_list->get(iter->object_list, iter->index);
    iter->index += 1;
    return item;
  }
  return NULL;
}

// 对象迭代器，实现了抽象迭代器的方法，聚合了数据对象
ObjectIterator *object_iterator_constructor(ObjectList *object_list)
{
  printf("\r\n object_iterator_constructor() [构建容器迭代器]");
  ObjectIterator *iter = (ObjectIterator *)malloc(sizeof(ObjectIterator));
  iter->object_list = object_list;
  iter->index = 0;
  iter->next = &next;
  iter->has_next = &has_next;
  return iter;
}