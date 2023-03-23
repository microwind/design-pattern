#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

/*
 * 指挥者，负责指挥建造者建造产品，隔离需求
 * 指挥者通过建造者建造产品的部件
 */

// 建造iphone
void build_iphone(Builder *builder)
{
  // 初始化建造者
  builder->reset(builder);
  // 调用建造者相应函数，建造产品的组成组件
  int screen[2] = {120, 500};
  builder->set_name(builder, "iPhone");
  builder->set_screen(builder, screen);
  builder->set_gpu_type(builder, 100);
  printf("build_iphone:[name=%s]", builder->get_name(builder));
}

// 建造huawei
void build_huawei_phone(Builder *builder)
{
  builder->reset(builder);
  int screen[2] = {140, 600};
  builder->set_name(builder, "HuaweiPhone");
  builder->set_screen(builder, screen);
  builder->set_gpu_type(builder, 102);
  printf("build_huawei_phone:[name=%s]", builder->get_name(builder));
}

// 建造mi
void build_mi_phone(Builder *builder)
{
  builder->reset(builder);
  int screen[2] = {130, 550};
  builder->set_name(builder, "MiPhone");
  builder->set_screen(builder, screen);
  builder->set_gpu_type(builder, 103);
  printf("build_mi_phone:[name=%s]", builder->get_name(builder));
}

// 初始化指挥者，申请Director空间
Director *create_director()
{
  Director *director = (Director *)malloc(sizeof(Director));
  director->build_iphone = &build_iphone;
  director->build_huawei_phone = &build_huawei_phone;
  director->build_mi_phone = &build_mi_phone;
  return director;
}