#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 创建抽象容器接口，创建一个迭代器，可选
typedef struct Container
{
    void (*set_objects)(struct Container *, char **objects, int);
    char **(*get_objects)(struct Container *);
    char *(*get)(struct Container *, int index);
    int length;
    // 字符串数组
    char **objects;
    struct Iterator *(*create_iterator)(struct Container *object_list);
} Container;

// 数据对象，是一种数据容器，实现了数据容器接口，可以创建一个迭代器
typedef struct ObjectList
{
    void (*set_objects)(struct ObjectList *, char **objects, int);
    char **(*get_objects)(struct ObjectList *);
    char *(*get)(struct ObjectList *, int index);
    int length;
    // 字符串数组
    char **objects;
    struct Iterator *(*create_iterator)(struct ObjectList *object_list);
} ObjectList;
ObjectList *object_list_constructor();

// 迭代器抽象接口，提供next和hasNext方法
typedef struct Iterator
{
    // 迭代器索引
    int index;
    // 数据对象数组
    struct ObjectList *object_list;
    bool (*has_next)(struct Iterator *);
    char *(*next)(struct Iterator *);
} Iterator;

// 对象迭代器，实现了抽象迭代器的方法，聚合了数据对象
typedef struct ObjectIterator
{
    // 迭代器索引
    int index;
    // 数据对象数组
    struct ObjectList *object_list;
    bool (*has_next)(struct Iterator *);
    char *(*next)(struct Iterator *);
} ObjectIterator;
ObjectIterator *object_iterator_constructor(ObjectList *object_list);
