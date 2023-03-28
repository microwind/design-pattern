#include "../func.h"

/* AgencyShop对象函数实现 */
void agency_shop_greetings(Shop *shop)
{
  printf("\r\n agency_shop_greetings() [name=%s]", shop->name);
}

/* 创建对象构造函数 */
AgencyShop *agency_shop_constructor(char *name)
{
  AgencyShop *agency_shop = (AgencyShop *)malloc(sizeof(AgencyShop));
  strncpy(agency_shop->name, name, 50);
  agency_shop->greetings = &agency_shop_greetings;
  return agency_shop;
}