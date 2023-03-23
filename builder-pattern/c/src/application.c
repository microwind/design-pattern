#include <stdio.h>
#include <stdlib.h>
#include "func.h"

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

void make_iphone()
{
  // 创建指挥者
  Director *director = create_director();

  // 创建手机建造者
  PhoneBuilder *phone_builder = create_phone_builder();
  // 指挥者通过建造者来创建对象
  director->build_iphone((Builder *)phone_builder);
  // 从建造者处获取产品对象
  Phone *phone = phone_builder->get_product(phone_builder);
  printf("\r\n get_product: %s | ", phone->name);
  print_phone(phone);
  free(phone_builder);

  // 创建手机建造者
  ManualBuilder *manual_builder = create_manual_builder();
  // 指挥者指挥建造者创建对象
  director->build_iphone((Builder *)manual_builder);
  // 从建造者处获取产品对象
  Manual *manual = ((Builder *)manual_builder)->get_manual_product((Builder *)manual_builder);
  printf("\r\n get_product: %s | ", manual->name);
  print_manual(manual);
  free(manual_builder);
}

void make_huawei_phone()
{
  // 创建指挥者
  Director *director = create_director();

  // 创建手机建造者
  PhoneBuilder *phone_builder = create_phone_builder();
  // 根据建造者来创建对象
  director->build_huawei_phone((Builder *)phone_builder);
  Phone *phone = phone_builder->get_product(phone_builder);
  // 根据建造者获取对象
  printf("\r\n get_product: %s | ", phone->name);
  print_phone(phone);
  free(phone_builder);

  // 创建手册建造者
  ManualBuilder *manual_builder = create_manual_builder();
  // 根据建造者来创建对象
  director->build_huawei_phone((Builder *)manual_builder);
  Manual *manual = ((Builder *)manual_builder)->get_manual_product((Builder *)manual_builder);
  // 根据建造者获取对象
  printf("\r\n get_product: %s | ", manual->name);
  print_manual(manual);
  free(manual_builder);
}