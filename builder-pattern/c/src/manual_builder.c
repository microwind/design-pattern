#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

/* 手册产品建造者 */

void reset_manual(Builder *builder)
{
  // 初始化Manual对象
  Manual *manual = (Manual *)malloc(sizeof(Manual));
  manual->name[0] = '\0';
  int screen_len = (int)sizeof(manual->screen) / sizeof(manual->screen[0]);
  for (int i = 0; i < screen_len; i++)
  {
    manual->screen[i] = 0;
  }
  manual->gpu_type = 0;
  builder->manual = manual;
}

void set_manual_name(Builder *builder, char *name)
{
  char display_name[50] = "Manual:";
  strcat(display_name, name);

  strncpy(builder->manual->name, display_name, 50);
}

char *get_manual_name(Builder *builder)
{
  return builder->manual->name;
}

void set_manual_screen(Builder *builder, int *screen)
{
  int screen_len = (int)sizeof(screen) / sizeof(screen[0]);
  memcpy(builder->manual->screen, screen, screen_len * sizeof(int));
}

void set_manual_gpu_type(Builder *builder, int gpu_type)
{
  builder->manual->gpu_type = gpu_type;
}

Manual *get_manual_product_by_builder(Builder *builder)
{
  return builder->manual;
}

Manual *get_manual_product(ManualBuilder *builder)
{
  return builder->manual;
}

// 初始化ManualBuilder对象以及Manual数据
ManualBuilder *create_manual_builder()
{
  // 申请Builder空间，创建基础Builder
  Builder *builder = (Builder *)malloc(sizeof(Builder));
  builder->manual = NULL;
  builder->reset = &reset_manual;
  builder->set_name = &set_manual_name;
  builder->get_name = &get_manual_name;
  builder->set_screen = &set_manual_screen;
  builder->set_gpu_type = &set_manual_gpu_type;
  builder->get_manual_product = &get_manual_product_by_builder;
  // 转成ManualBuilder对象
  ManualBuilder *manual_builder = (ManualBuilder *)builder;
  manual_builder->get_product = &get_manual_product;
  return manual_builder;
}