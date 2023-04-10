#include "func.h"

/* 具体享元角色，实现抽象接口，用于共享状态，一个类被创建以后就不用重复创建了 */

// 享元对象实例化函数，对象实例化后共享对象
// state属于外部状态，由外部调用时传入，也可以把非共享的对象传入进来
void concrete_flyweight_operate(ConcreteFlyweight *flyweight, char *state)
{
  printf("\r\n ConcreteFlyweight::operate() [name=%s kind=%s state=%s]", flyweight->name, flyweight->kind, state);
}

ConcreteFlyweight *concrete_flyweight_constructor(char *name)
{
  printf("\r\n ConcreteFlyweight::concrete_flyweight_constructor() 创建具体享元对象[name=%s]", name);
  Flyweight *flyweight = (Flyweight *)malloc(sizeof(Flyweight));
  strncpy(flyweight->name, name, 50);
  strncpy(flyweight->kind, "piano", 50);
  ConcreteFlyweight *concrete_flyweight = (ConcreteFlyweight *)flyweight;
  concrete_flyweight->operate = &concrete_flyweight_operate;
  return concrete_flyweight;
}