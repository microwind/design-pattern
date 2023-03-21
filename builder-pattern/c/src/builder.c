#include <string.h>
#include <stdlib.h>
#include "func.h"

// 初始化Builder对象
Builder *create_builder()
{
  // 申请Builder空间
  Builder *builder = (Builder *)malloc(sizeof(Builder));
  builder->phone = NULL;
  builder->manual = NULL;
  return builder;
}