#include "../func.h"

/* SupermarketShop对象函数实现 */
void supermarket_shop_greetings(Shop *shop)
{
  printf("\r\n supermarket_shop_greetings() [name=%s]", shop->name);
}

/* 创建对象构造函数 */
SupermarketShop *supermarket_shop_constructor(char *name)
{
  SupermarketShop *supermarket_shop = (SupermarketShop *)malloc(sizeof(SupermarketShop));
  strncpy(supermarket_shop->name, name, 50);
  supermarket_shop->greetings = &supermarket_shop_greetings;
  return supermarket_shop;
}