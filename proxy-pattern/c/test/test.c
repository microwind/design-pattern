#include "../src/func.h"

int main(void)
{
  printf("test start:\r\n");
  /**
   * 代理模式就是用一个类来代理另一个类或几个类的功能，以便隔绝外部客户和内部真实类
   * 这样真实类和调用方之间有一个代理屏障，保证了安全
   * 同时真实的类如果初始化过，就不再初始化，提升了性能
   */

  // 声明代理类来执行真实类的能力
  Image *image = (Image *)proxy_image_constructor("abc.png");
  image->set_file_name(image, "001.jpg");

  // 代理类执行真实类的能力
  image->display(image);

  // 再调用一次，不会重复实例化
  image->display(image);
}

// jarry@jarrys-MacBook-Pro c % gcc test/test.c ./src/*.c
// jarry@jarrys-MacBook-Pro c % ./a.out
/**
test start:

 proxy_image_constructor() [构建ProxyImage]
 ProxyImage::display() [file_name=001.jpg]
 real_image_constructor() [构建RealImage]
 RealImage::load_from_disk() [file_name=001.jpg]
 RealImage::display() [file_name=001.jpg]
 ProxyImage::display() [file_name=001.jpg]
 RealImage::display() [file_name=001.jpg]% 
 */