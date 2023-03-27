#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

/* Van对象函数实现 */
void van_run()
{
  printf("Van::Run(). \r\n");
}

/* 创建具体处理器的函数 */
Van *van_constructor(char *name)
{
  Van *van = (Van *)malloc(sizeof(Van));
  strncpy(van->name, name, 50);
  van->run = &van_run;
  return van;
}