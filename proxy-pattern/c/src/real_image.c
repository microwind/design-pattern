#include "func.h"

// 真实类实现基础接口

// 这个方法只是内部使用
void real_image_load_from_disk(RealImage *image, char *file_name)
{
  printf("\r\n RealImage::load_from_disk() [file_name=%s]", file_name);
}

// 在初始化时执行内部逻辑
void real_image_init(RealImage *image, char *file_name)
{
  strcpy(image->file_name, file_name);
  real_image_load_from_disk(image, file_name);
}

void real_image_display(RealImage *image)
{
  printf("\r\n RealImage::display() [file_name=%s]", image->file_name);
}

RealImage *real_image_constructor(char *file_name)
{
  printf("\r\n real_image_constructor() [构建RealImage]");
  Image *image = (Image *)malloc(sizeof(Image));
  strcpy(image->file_name, file_name);
  image->set_file_name = &image_set_file_name;
  RealImage *real_image = (RealImage *)image;
  real_image->real_image = NULL;
  real_image->display = &real_image_display;
  return real_image;
}