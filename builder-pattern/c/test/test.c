#include <stdio.h>
#include "../src/func.h"

// main包下的main入口方法
int main()
{
  printf("\r\ntest start:\r\n");
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
  // 创建手机
  Builder *phone_builder = create_builder();
  build_mi_phone((PhoneBuilder *)phone_builder);
  Phone *phone = get_phone_product((PhoneBuilder *)phone_builder);
  printf("mi phone: %s | ", phone->name);
  print_phone(phone);
  free_phone_builder((PhoneBuilder *)phone_builder);

  // 创建手册
  Builder *manual_builder = create_builder();
  build_mi_manual((ManualBuilder *)manual_builder);
  Manual *manual = get_manual_product((ManualBuilder *)manual_builder);
  printf("mi manual: %s | ", manual->name);
  print_manual(manual);
  free_manual_builder((ManualBuilder *)manual_builder);
}

/**
jarry@jarrys-MacBook-Pro c % gcc test/*.c src/*.c
jarry@jarrys-MacBook-Pro c % ./a.out             

test start:
iphone: iPhone | { name: "iPhone", screen: [120, 500], gpu_type: 100 } 
iphone manual: iPhone | { name: "iPhone", screen: [120, 500], gpu_type: 100 } 
huawei phone: HuaweiPhone{ name: "HuaweiPhone", screen: [140, 600], gpu_type: 102 } 
huawei manual: HuaweiPhone{ name: "HuaweiPhone", screen: [140, 600], gpu_type: 102 } 
mi phone: MiPhone | { name: "MiPhone", screen: [130, 550], gpu_type: 103 } 
mi manual: MiPhone | { name: "MiPhone", screen: [130, 550], gpu_type: 103 } 
*/