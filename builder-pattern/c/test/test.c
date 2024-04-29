#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../src/func.h"

// main包下的main入口方法
int main()
{
  printf("test start:\r\n");
  /**
   * 建造者模式是使用多个简单的对象一步一步构建出一个复杂的对象来。
   * 分为主管类和建造者类，主管类负责具体指挥调度，建造负责具体实施。
   * 主管类通过一步一步调用各种建造者实现复杂对象。
   */

  // 调用application来创建
  make_iphone();
  make_huawei_phone();

  // *********************** 分割线 ******************************************/
  // 直接调用director相关方法

  // 创建指挥者
  Director *director = create_director();

  // 创建mi手机
  PhoneBuilder *phone_builder = create_phone_builder();
  director->build_mi_phone((Builder *)phone_builder);
  Phone *phone = phone_builder->get_product(phone_builder);
  // 根据建造者获取对象
  printf("\r\n get_product: %s | ", phone->name);
  print_phone(phone);
  free(phone_builder);

  // 创建huawei手册
  ManualBuilder *manual_builder = create_manual_builder();
  director->build_huawei_phone((Builder *)manual_builder);
  Manual *manual = manual_builder->get_product(manual_builder);
  // 根据建造者获取对象
  printf("\r\n get_product 1111: %s | ", manual->name);
  print_manual(manual);
  free(manual_builder);
}

// jarry@jarrys-MacBook-Pro c % gcc src/*.c test/test.c
// jarry@jarrys-MacBook-Pro c % ./a.out
/**
test start:
build_iphone:[name=Phone:iPhone]
 get_product: Phone:iPhone | { name: "Phone:iPhone", screen: [120, 500], gpu_type: 100 }
build_iphone:[name=Manual:iPhone]
 get_product: Manual:iPhone | { name: "Manual:iPhone", screen: [120, 500], gpu_type: 100 }
build_huawei_phone:[name=Phone:HuaweiPhone]
 get_product: Phone:HuaweiPhone | { name: "Phone:HuaweiPhone", screen: [140, 600], gpu_type: 102 }
build_huawei_phone:[name=Manual:HuaweiPhone]
 get_product: Manual:HuaweiPhone | { name: "Manual:HuaweiPhone", screen: [140, 600], gpu_type: 102 }
build_mi_phone:[name=Phone:MiPhone]
 get_product: Phone:MiPhone | { name: "Phone:MiPhone", screen: [130, 550], gpu_type: 103 }
build_huawei_phone:[name=Manual:HuaweiPhone]
 get_product: Manual:HuaweiPhone | { name: "Manual:HuaweiPhone", screen: [140, 600], gpu_type: 102 }
*/