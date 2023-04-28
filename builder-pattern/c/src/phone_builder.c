#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

/* 手机产品建造者，提供各种建造产品部件的方法，供指挥者调用 */

void reset_phone(Builder *builder)
{
  // 初始化Phone对象
  Phone *phone = (Phone *)malloc(sizeof(Phone));
  phone->name[0] = '\0';
  int screen_len = (int)sizeof(phone->screen) / sizeof(phone->screen[0]);
  for (int i = 0; i < screen_len; i++)
  {
    phone->screen[i] = 0;
  }
  phone->gpu_type = 0;
  builder->phone = phone;
}

Builder *set_phone_name(Builder *builder, char *name)
{
  char display_name[50] = "Phone:";
  strcat(display_name, name);

  strncpy(builder->phone->name, display_name, 50);
  return builder;
}

char *get_phone_name(Builder *builder)
{
  return builder->phone->name;
}

Builder *set_phone_screen(Builder *builder, int *screen)
{
  int screen_len = (int)sizeof(screen) / sizeof(screen[0]);
  memcpy(builder->phone->screen, screen, screen_len * sizeof(int));
  return builder;
}

Builder *set_phone_gpu_type(Builder *builder, int gpu_type)
{
  builder->phone->gpu_type = gpu_type;
  return builder;
}

Phone *get_phone_product(PhoneBuilder *builder)
{
  return builder->phone;
}

// 初始化PhoneBuilder对象以及Phone数据
PhoneBuilder *create_phone_builder()
{
  // 申请Builder空间，创建基础Builder
  Builder *builder = (Builder *)malloc(sizeof(Builder));
  builder->phone = NULL;
  builder->reset = &reset_phone;
  builder->set_name = &set_phone_name;
  builder->get_name = &get_phone_name;
  builder->set_screen = &set_phone_screen;
  builder->set_gpu_type = &set_phone_gpu_type;
  // builder->get_phone_product = &get_phone_product;
  // 转成PhoneBuilder对象
  PhoneBuilder *phone_builder = (PhoneBuilder *)builder;
  phone_builder->get_product = &get_phone_product;
  return phone_builder;
}