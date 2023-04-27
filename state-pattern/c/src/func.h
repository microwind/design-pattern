#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Context Context;
typedef struct State State;

// 定义状态接口和状态方法，当前context只有一种状态
typedef struct State
{
  char name[50];
  void (*on)(Context *context);
  void (*off)(Context *context);
} State;

// 具体执行实体类，内部关联状态
typedef struct Context
{
  State *state;
  void (*set_state)(Context *context, State *state);
  State *(*get_state)(Context *context);
  void (*turn_on)(Context *context);
  void (*turn_off)(Context *context);
} Context;
Context *context_constructor();

// 具体的状态实现者
typedef struct ConcreteStateOff
{
  char name[50];
  void (*on)(Context *context);
  void (*off)(Context *context);
} ConcreteStateOff;
ConcreteStateOff *concrete_state_off_constructor();

// 具体的状态实现者
typedef struct ConcreteStateOn
{
  char name[50];
  void (*on)(Context *context);
  void (*off)(Context *context);
} ConcreteStateOn;
ConcreteStateOn *concrete_state_on_constructor();