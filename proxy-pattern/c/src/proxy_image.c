#include "func.h"

// 代理类实现了基础接口

void proxy_image_display(ProxyImage *image)
{
  printf("\r\n ProxyImage::display() [file_name=%s]", image->file_name);
  if (image->real_image == NULL)
  {
    image->real_image = real_image_constructor(image->file_name);
    real_image_init(image->real_image, image->file_name);
  }
  // 代理类调用真实类的display
  image->real_image->display(image->real_image);
}

ProxyImage *proxy_image_constructor(char *file_name)
{
  printf("\r\n proxy_image_constructor() [构建ProxyImage]");
  Image *image = (Image *)malloc(sizeof(Image));
  strcpy(image->file_name, file_name);
  image->set_file_name = &image_set_file_name;
  ProxyImage *proxy_image = (ProxyImage *)image;
  proxy_image->display = &proxy_image_display;
  return proxy_image;
}