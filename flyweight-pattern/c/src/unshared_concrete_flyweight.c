#include "func.h"

/* 无需共享实例的角色，用于处理外部非共享状态 */

// 非共享对象的外部状态，这里state属于外部状态，在调用时外部传入。
void unshared_flyweight_operate(UnsharedConcreteFlyweight *flyweight, char *state)
{
  printf("\r\n UnsharedConcreteFlyweight::operate() [name=%s kind=%s state=%s]", flyweight->name, flyweight->kind, state);
}

// 无需共享的角色，每次都是新实例
UnsharedConcreteFlyweight *unshared_concrete_flyweight_constructor(char *name)
{
  printf("\r\n UnsharedConcreteFlyweight::unshared_concrete_flyweight_constructor() 创建非共享对象[name=%s]", name);
  Flyweight *flyweight = (Flyweight *)malloc(sizeof(Flyweight));
  strncpy(flyweight->name, name, 50);
  strncpy(flyweight->kind, "guitar", 50);
  UnsharedConcreteFlyweight *unshared_flyweight = (UnsharedConcreteFlyweight *)flyweight;
  unshared_flyweight->operate = &unshared_flyweight_operate;
  return unshared_flyweight;
}