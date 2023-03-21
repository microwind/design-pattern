#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

/* 手册建造者 */

// 初始化ManualBuilder对象
ManualBuilder *create_manual_builder()
{
  ManualBuilder *builder = (ManualBuilder *)malloc(sizeof(ManualBuilder));
  builder->manual = NULL;
  return builder;
}

void reset_manual(ManualBuilder *builder)
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

Manual *get_manual_product(ManualBuilder *builder)
{
  return builder->manual;
}

void free_manual_builder(ManualBuilder *builder)
{
  free(builder);
}

void set_manual_name(ManualBuilder *builder, char *name)
{
  strncpy(builder->manual->name, name, 50);
}

char *get_manual_name(ManualBuilder *builder)
{
  return builder->manual->name;
}

void set_manual_screen(ManualBuilder *builder, int *screen)
{
  int screen_len = (int)sizeof(screen) / sizeof(screen[0]);
  memcpy(builder->manual->screen, screen, screen_len * sizeof(int));
}

int *get_manual_screen(ManualBuilder *builder)
{
  return builder->manual->screen;
}

void set_manual_gpu_type(ManualBuilder *builder, int gpu_type)
{
  builder->manual->gpu_type = gpu_type;
}

int get_manual_gpu_type(ManualBuilder *builder)
{
  return builder->manual->gpu_type;
}