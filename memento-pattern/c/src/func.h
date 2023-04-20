#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 备忘录(Memento)角色，负责存储发起人传入的状态
typedef struct Memento
{
    char name[50];
    char state[50];
    void (*set_state)(struct Memento *memento, char *state);
    char *(*get_state)(struct Memento *memento);
} Memento;
Memento *memento_constructor(char *name, char *state);

// 负责人(Caretaker)角色，只负责保存备忘录记录，不能修改备忘录对象的内容
typedef struct Caretaker
{
    Memento **memento_list;
    int memento_length;
    void (*add)(struct Caretaker *caretaker, Memento *memento);
    Memento *(*get)(struct Caretaker *caretaker, int index);
} Caretaker;
Caretaker *caretaker_constructor();

// 发起人(Originator)负责生成状态快照，即利用一个新备忘录对象将自己的内部状态存储起来
typedef struct Originator
{
    char state[50];
    struct Memento *(*save_memento)(struct Originator *originator);
    void (*restore_memento)(struct Originator *originator, struct Memento *memento);
    void (*set_state)(struct Originator *originator, char *state);
    char *(*get_state)(struct Originator *originator);
} Originator;
Originator *originator_constructor();