#include <stdio.h>
#include <stdlib.h>

// 简单版C语言迭代器模式，自己构建List数据类型

// 数据结构，这里使用链表作为示例
struct List
{
  char *data;
  struct List *next;
};

// 迭代器结构体
struct Iterator
{
  struct List *current;
  int (*has_next)(struct Iterator *);        // 判断是否还有下一个元素
  char *(*next)(struct Iterator *, char **); // 获取下一个元素
};

// 判断是否还有下一个元素
int has_next(struct Iterator *iter)
{
  return iter->current != NULL;
}

// 获取下一个元素
char *next(struct Iterator *iter, char **value)
{
  if (iter->current == NULL)
  {
    return NULL;
  }
  *value = iter->current->data;
  iter->current = iter->current->next;
  return *value;
}

// 初始化迭代器
void create_iterator(struct Iterator *iter, struct List *head)
{
  iter->current = head;
  iter->has_next = &has_next;
  iter->next = &next;
}

// 遍历链表
void iterate_list(struct List *head)
{
  struct Iterator iter;
  char *value;
  create_iterator(&iter, head);
  while (iter.has_next(&iter))
  {
    iter.next(&iter, &value);
    printf("\r\n %s ", value);
  }
  printf("\n");
}

int main()
{
  printf("test start:\r\n");
  // 构造一个链表
  struct List *head = (struct List *)malloc(sizeof(struct List));
  head->data = "Tom";
  head->next = (struct List *)malloc(sizeof(struct List));
  head->next->data = "Jerry";
  head->next->next = (struct List *)malloc(sizeof(struct List));
  head->next->next->data = "Max";
  head->next->next->next = NULL;

  // 使用迭代器遍历链表
  iterate_list(head);

  // 释放链表内存
  while (head != NULL)
  {
    struct List *temp = head;
    head = head->next;
    free(temp);
  }

  return 0;
}

/**
jarry@jarrys-MacBook-Pro c % gcc test/simple_iterator.c
jarry@jarrys-MacBook-Pro c % ./a.out 
test start:

 Tom 
 Jerry 
 Max 
*/