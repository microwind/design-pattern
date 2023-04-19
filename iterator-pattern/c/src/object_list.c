#include "func.h"

void object_list_set_objects(ObjectList *object_list, char **objects, int len)
{
  object_list->length = len;
  object_list->objects = objects;
}

char **object_list_get_objects(ObjectList *object_list)
{
  return object_list->objects;
}

char *object_list_get(ObjectList *object_list, int index)
{
  return object_list->objects[index];
}

Iterator *create_iterator(ObjectList *object_list)
{
  // 创建迭代器实例，绑定新建当前对象
  return (Iterator *)object_iterator_constructor(object_list);
}

// 数据对象，是一种具体的数据容器，实现了数据容器抽象接口，可以创建一个迭代器
ObjectList *object_list_constructor()
{
  printf("\r\n object_list_constructor() [构建数据容器对象]");
  Container *obj = (Container *)malloc(sizeof(Container));
  ObjectList *list = (ObjectList *)obj;
  list->objects = NULL;
  list->length = 0;
  list->set_objects = &object_list_set_objects;
  list->get_objects = &object_list_get_objects;
  list->get=&object_list_get;
  list->create_iterator = &create_iterator;
  return list;
}