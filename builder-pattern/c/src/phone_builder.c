#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

/* 手机建造者 */

// 初始化PhoneBuilder对象以及Phone数据
PhoneBuilder *create_phone_builder()
{
  // 申请PhoneBuilder空间
  PhoneBuilder *builder = (PhoneBuilder *)malloc(sizeof(PhoneBuilder));
  builder->phone = NULL;
  return builder;
}

void reset_phone(PhoneBuilder *builder)
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

Phone *get_phone_product(PhoneBuilder *builder)
{
  return builder->phone;
}

void free_phone_builder(PhoneBuilder *builder)
{
  free(builder);
}

void set_phone_name(PhoneBuilder *builder, char *name)
{
  strncpy(builder->phone->name, name, 50);
}

char *get_phone_name(PhoneBuilder *builder)
{
  return builder->phone->name;
}

void set_phone_screen(PhoneBuilder *builder, int *screen)
{
  int screen_len = (int)sizeof(screen) / sizeof(screen[0]);
  memcpy(builder->phone->screen, screen, screen_len * sizeof(int));
}

int *get_phone_screen(PhoneBuilder *builder)
{
  return builder->phone->screen;
}

void set_phone_gpu_type(PhoneBuilder *builder, int gpu_type)
{
  builder->phone->gpu_type = gpu_type;
}

int get_phone_gpu_type(PhoneBuilder *builder)
{
  return builder->phone->gpu_type;
}