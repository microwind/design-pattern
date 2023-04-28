# 【模板方法设计模式详解】C/Java/JS/Go/Python/TS不同语言实现

# 简介
模板方法模式（Template Method Pattern）也叫模板模式，是一种行为型模式。它定义了一个抽象公开类，包含基本的算法骨架，而将一些步骤延迟到子类中，模板方法使得子类可以不改变算法的结构，只是重定义该算法的某些特定步骤。不同的子类以不同的方式实现这些抽象方法，从而对剩余的逻辑有不同的实现。以此基于公共的模板，来实现实现不同的功能。

模板模式适用于一些复杂操作进行步骤分割、抽取公共部分由抽象父类实现、将不同的部分在父类中定义抽象实现、而将具体实现过程由子类完成。对于有多个子类具有共有的方法，且逻辑相同，可以考虑作为模板方法。

# 作用
1. 相同的部分父类给出统一的模板，子类大量复用，从而节省代码，复用逻辑。
2. 封装不变部分，扩展可变部分，行为由父类控制，子类灵活实现，便于维护和扩展。

# 实现步骤
1. 创建一个抽象的模板类，定义基本流程，同时定义一些基本方法供子类去实现。
2. 创建多个子类继承抽象模板，覆盖父类的相关动作和方法。

# UML
<img src="../docs/uml/template-pattern.png">

# Java代码

## 抽象模板类
```java
// GameTemplate.java 定义抽象模板类，有抽象方法和具体方法
public abstract class GameTemplate {

   // 抽象方法待子类来实现
   abstract void init();

   abstract void start();

   abstract void end();

   // 可复用的算法流程
   public void play() {

      System.out.println(this.getClass().getSimpleName() + "::play()");

      // 初始化游戏
      init();

      // 开始游戏
      start();

      // 结束游戏
      end();
   }

}
```

## 具体业务类，继承抽象模板
```java
// Basketball.java  定义子类覆写父类抽象方法
public class Basketball extends GameTemplate {

   @Override
   void init() {
      System.out.println("Basketball::init() [Basketball Game Initialized! Start playing.]");
   }

   @Override
   void start() {
      System.out.println("Basketball::start() [Basketball Game Started. Enjoy the game!]");
   }

   @Override
   void end() {
      System.out.println("Basketball::end() [Basketball Game Finished!]");
   }

}
```

```java
// Football.java 定义子类覆写父类抽象方法
public class Football extends GameTemplate {

   @Override
   void init() {
      System.out.println("Football::init() [Football Game Initialized! Start playing.]");
   }

   @Override
   void start() {
      System.out.println("Football::start() [Football Game Started. Enjoy the game!]");
   }

   @Override
   void end() {
      System.out.println("Football::end() [Football Game Finished!]");
   }

}
```

```java
// Tennis.java 定义子类覆写父类抽象方法
public class Tennis extends GameTemplate {

   @Override
   void init() {
      System.out.println("Tennis::init() [Tennis Game Initialized! Start playing.]");
   }

   @Override
   void start() {
      System.out.println("Tennis::start() [Tennis Game Started. Enjoy the game!]");
   }

   @Override
   void end() {
      System.out.println("Tennis::end() [Tennis Game Finished!]");
   }

   // 在调用父类play之前，如果要执行自己的行为，也可以覆盖父类方法
   // 先执行自己的，再调用父类的方法
   @Override
   public void play() {
      System.out.println("Tennis::play() [Tennis Game play!]");
      super.play();
   }
}
```

## 测试调用
```java
    /**
     * 模板方法模式就是当子类具备类似行为的时候，让子类共用一套流程
     * 创建一个公共模板，确定公用流程和操作动作，子类覆盖具体的动作
     */
    GameTemplate football = new Football();
    football.play();

    System.out.println("===");
    GameTemplate basketball = new Basketball();
    basketball.play();

    System.out.println("===");
    GameTemplate tennis = new Tennis();
    tennis.play();
```

# C语言代码

## 头文件
// func.h
```c
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

```

## 抽象模板类
```c
// game_template.c 定义抽象模板类，有抽象方法和具体方法
#include "func.h"

// 定义抽象模板类的公共部分，这里用struct替代

// 抽象方法待子类来实现
void template_init(GameTemplate *game) {}
void template_start(GameTemplate *game)
{
  printf("\r\n GameTemplate::start() [GameTemplate Initialized! Start playing.]");
}
void template_end(GameTemplate *game) {}

// 可复用的算法流程
void template_play(GameTemplate *game)
{
  printf("\r\n GameTemplate::play() [name=%s]", game->name);

  // 初始化游戏
  game->init(game);

  // 开始游戏
  game->start(game);

  // 结束游戏
  game->end(game);
}

GameTemplate *game_template_constructor(char *name)
{
  // printf("\r\n game_template_constructor() [构建GameTemplate]");
  GameTemplate *game = (GameTemplate *)malloc(sizeof(GameTemplate));
  strcpy(game->name, name);
  game->init = &template_init;
  game->start = &template_start;
  game->end = &template_end;
  game->play = &template_play;
  return game;
}
```

## 具体业务类，继承抽象模板
```c
// basketball.c  定义子类覆写父类抽象方法
#include "func.h"

// 定义子类覆写父类抽象方法
void basketball_init(Basketball *game)
{
  printf("\r\n Basketball::init() [Basketball Game Initialized! Start playing.]");
}

void basketball_start(Basketball *game)
{
  printf("\r\n Basketball::start() [Basketball Game Started. Enjoy the game!]");
}

void basketball_end(Basketball *game)
{
  printf("\r\n Basketball::end() [Basketball Game Finished!]");
}

Basketball *basketball_constructor(char *name)
{
  printf("\r\n basketball_constructor() [构建Basketball]");
  GameTemplate *template = game_template_constructor(name);
  Basketball *game = (Basketball *)template;
  game->init = &basketball_init;
  // 如果不覆盖则使用基类的函数
  // game->start = &basketball_start;
  game->end = &basketball_end;
  return game;
}
```

```c
// football.c 定义子类覆写父类抽象方法
#include "func.h"

// 定义子类覆写父类抽象方法
void football_init(Football *game)
{
  printf("\r\n Football::init() [Football Game Initialized! Start playing.]");
}

void football_start(Football *game)
{
  printf("\r\n Football::start() [Football Game Started. Enjoy the game!]");
}

void football_end(Football *game)
{
  printf("\r\n Football::end() [Football Game Finished!]");
}

Football *football_constructor(char *name)
{
  printf("\r\n football_constructor() [构建Football]");
  GameTemplate *template = game_template_constructor(name);
  Football *game = (Football *)template;
  game->init = &football_init;
  game->start = &football_start;
  game->end = &football_end;
  return game;
}
```

```c
// tennis.c 定义子类覆写父类抽象方法
#include "func.h"

// 定义子类覆写父类抽象方法
void tennis_init(Tennis *game)
{
  printf("\r\n Tennis::init() [Tennis Game Initialized! Start playing.]");
}

void tennis_start(Tennis *game)
{
  printf("\r\n Tennis::start() [Tennis Game Started. Enjoy the game!]");
}

void tennis_end(Tennis *game)
{
  printf("\r\n Tennis::end() [Tennis Game Finished!]");
}

// 在调用父类play之前，如果要执行自己的行为，也可以覆盖父类方法
void tennis_play(Tennis *game)
{
  // 先执行自己的内容，再调用基类的函数
  printf("\r\n Tennis::play() [Tennis Game Play!]");
  template_play((GameTemplate *)game);
}

Tennis *tennis_constructor(char *name)
{
  printf("\r\n tennis_constructor() [构建Tennis]");
  GameTemplate *template = game_template_constructor(name);
  Tennis *game = (Tennis *)template;
  game->init = &tennis_init;
  game->start = &tennis_start;
  game->end = &tennis_end;
  game->play = &tennis_play;
  return game;
}
```

## 测试调用
```c
#include "../src/func.h"

int main(void)
{
  printf("test start:\r\n");
  /**
   * 模板方法模式就是当子类具备类似行为的时候，让子类共用一套流程
   * 创建一个公共模板，确定公用流程和操作动作，子类覆盖具体的动作
   */
  Football *football = football_constructor("football");
  football->play(football);

  printf("\r\n ===");
  Basketball *basketball = basketball_constructor("basketball");
  basketball->play(basketball);

  printf("\r\n ===");
  Tennis *tennis = tennis_constructor("basketball");
  tennis->play(tennis);
}

```

## 更多语言版本
不同语言设计模式源码：[https://github.com/microwind/design-pattern](https://github.com/microwind/design-pattern)