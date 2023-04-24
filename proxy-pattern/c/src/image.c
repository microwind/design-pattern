#include "func.h"

// 基础接口，供代理类和真实类实现，定义在head

// 设置文件名称
void image_set_file_name(Image *image, char *file_name)
{
  strcpy(image->file_name, file_name);
}