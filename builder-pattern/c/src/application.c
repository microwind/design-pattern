#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void print_phone(Phone *phone)
{
  printf("{ name: \"%s\"", phone->name);
  int screen_len = (int)sizeof(phone->screen) / sizeof(phone->screen[0]);
  printf(", screen: [");
  for (int i = 0; i < screen_len; i++)
  {
    printf("%d", phone->screen[i]);
    if (i != screen_len - 1)
    {
      printf(", ");
    }
  }
  printf("]");
  printf(", gpu_type: %d } \r\n", phone->gpu_type);
}

void print_manual(Manual *manual)
{
  printf("{ name: \"%s\"", manual->name);
  int screen_len = (int)sizeof(manual->screen) / sizeof(manual->screen[0]);
  printf(", screen: [");
  for (int i = 0; i < screen_len; i++)
  {
    printf("%d", manual->screen[i]);
    if (i != screen_len - 1)
    {
      printf(", ");
    }
  }
  printf("]");
  printf(", gpu_type: %d } \r\n", manual->gpu_type);
}

void make_iphone()
{
  // 创建手机建造者
  PhoneBuilder *phone_builder = create_phone_builder();
  // 根据建造者来创建对象
  build_iphone(phone_builder);
  Phone *phone = get_phone_product(phone_builder);
  // 根据建造者获取对象
  printf("iphone: %s | ", phone->name);
  print_phone(phone);
  free_phone_builder(phone_builder);

  // 创建手册建造者
  ManualBuilder *manual_builder = create_manual_builder();
  // 根据建造者来创建对象
  build_iphone_manual(manual_builder);
  // 根据建造者获取对象
  Manual *manual = get_manual_product(manual_builder);
  printf("iphone manual: %s | ", manual->name);
  print_manual(manual);
  free_manual_builder(manual_builder);

}

void make_huawei_phone()
{
  // 创建手机建造者
  PhoneBuilder *phone_builder = create_phone_builder();
  // 根据建造者来创建对象
  build_huawei_phone(phone_builder);
  Phone *phone = get_phone_product(phone_builder);
  // 根据建造者获取对象
  printf("huawei phone: %s", phone->name);
  print_phone(phone);
  free_phone_builder(phone_builder);

  // 创建手册建造者
  ManualBuilder *manual_builder = create_manual_builder();
  // 根据建造者来创建对象
  build_huawei_manual(manual_builder);
  // 根据建造者获取对象
  Manual *manual = get_manual_product(manual_builder);
  printf("huawei manual: %s", manual->name);
  print_manual(manual);
  free_manual_builder(manual_builder);
}