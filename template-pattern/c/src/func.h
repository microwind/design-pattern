#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct GameTemplate GameTemplate;
typedef struct Football Football;
typedef struct Basketball Basketball;
typedef struct Tennis Tennis;

// 定义抽象模板，包括各种动作和公共流程
typedef struct GameTemplate
{
  char name[50];
  void (*init)(GameTemplate *game);
  void (*start)(GameTemplate *game);
  void (*end)(GameTemplate *game);
  void (*play)(GameTemplate *game);
} GameTemplate;
void template_play(GameTemplate *game);
GameTemplate *game_template_constructor(char *name);

// 定义子类覆写父类抽象方法
typedef struct Football
{
  char name[50];
  void (*init)(Football *game);
  void (*start)(Football *game);
  void (*end)(Football *game);
  void (*play)(Football *game);
} Football;
Football *football_constructor(char *name);

// 定义子类覆写父类抽象方法
typedef struct Basketball
{
  char name[50];
  void (*init)(Basketball *game);
  void (*start)(Basketball *game);
  void (*end)(Basketball *game);
  void (*play)(Basketball *game);
} Basketball;
Basketball *basketball_constructor(char *name);

// 定义子类覆写父类抽象方法
typedef struct Tennis
{
  char name[50];
  void (*init)(Tennis *game);
  void (*start)(Tennis *game);
  void (*end)(Tennis *game);
  void (*play)(Tennis *game);
} Tennis;
Tennis *tennis_constructor(char *name);
