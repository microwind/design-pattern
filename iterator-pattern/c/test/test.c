#include "../src/func.h"

int main(void)
{
  printf("test start:\r\n");
  /*
   * 迭代器模式是给数据容器创建单独的迭代器，用来遍历里面的数据对象
   * 数据容器和迭代器相互关联，外部通过迭代器来访问数据容器
   * 通过这种方式由迭代器类来负责数据遍历，这样可以做到不暴露集合的内部结构
   */
  int i = 0;
  Container *container = (Container *)object_list_constructor();
  ObjectList *object_list = (ObjectList *)container;
  char *arr[6] = {"Thomas", "Merry", "Jack", "Tony", "Jerry", "Joey"};
  object_list->set_objects(object_list, arr, 6);

  // for循环迭代对象
  for (Iterator *iter = object_list->create_iterator(object_list); iter->has_next(iter);)
  {
    char *name = iter->next(iter);
    printf("\r\n objectList[%d] = %s", i, name);
    i++;
  }

  // while迭代器遍历模式
  ObjectList *object_list2 = object_list_constructor();
  object_list2->set_objects(object_list2, arr, 6);
  Iterator *iter2 = object_list->create_iterator(object_list);
  while (iter2->has_next(iter2))
  {
    printf("\r\n %s", iter2->next(iter2));
    if (iter2->has_next(iter2) == false)
    {
      break;
    }
  }

  free(container);
}

/**
jarry@jarrys-MacBook-Pro c % gcc test/test.c src*.c
jarry@jarrys-MacBook-Pro c % ./a.out
test start:

 object_list_constructor() [构建数据容器对象]
 object_iterator_constructor() [构建容器迭代器]
 objectList[0] = Thomas
 objectList[1] = Merry
 objectList[2] = Jack
 objectList[3] = Tony
 objectList[4] = Jerry
 objectList[5] = Joey
 object_list_constructor() [构建数据容器对象]
 object_iterator_constructor() [构建容器迭代器]
 Thomas
 Merry
 Jack
 Tony
 Jerry
 Joey% 
 */