#include <stdio.h>
#include "func.h"

/*
 * 指挥者，负责指挥建造者建造产品，隔离需求
 * c语言里没有类也不支持函数重载，这里仅用作函数集合
 */

// 建造phone的iphone
void build_iphone(PhoneBuilder *builder)
{
  reset_phone(builder);
  int screen[2] = {120, 500};
  set_phone_name(builder, "iPhone");
  set_phone_screen(builder, screen);
  set_phone_gpu_type(builder, 100);
}

// 建造phone的huwei phone
void build_huawei_phone(PhoneBuilder *builder)
{
  reset_phone(builder);
  int screen[2] = {140, 600};
  set_phone_name(builder, "HuaweiPhone");
  set_phone_screen(builder, screen);
  set_phone_gpu_type(builder, 102);
}

// 建造phone的mi phone
void build_mi_phone(PhoneBuilder *builder)
{
  reset_phone(builder);
  int screen[2] = {130, 550};
  set_phone_name(builder, "MiPhone");
  set_phone_screen(builder, screen);
  set_phone_gpu_type(builder, 103);
}

// 建造iphone手册
void build_iphone_manual(ManualBuilder *builder)
{
  reset_manual(builder);
  int screen[2] = {120, 500};
  set_manual_name(builder, "iPhone");
  set_manual_screen(builder, screen);
  set_manual_gpu_type(builder, 100);
}

// 建造huwei manual手册
void build_huawei_manual(ManualBuilder *builder)
{
  reset_manual(builder);
  int screen[2] = {140, 600};
  set_manual_name(builder, "HuaweiPhone");
  set_manual_screen(builder, screen);
  set_manual_gpu_type(builder, 102);
}

// 建造mi manual手册
void build_mi_manual(ManualBuilder *builder)
{
  reset_manual(builder);
  int screen[2] = {130, 550};
  set_manual_name(builder, "MiPhone");
  set_manual_screen(builder, screen);
  set_manual_gpu_type(builder, 103);
}