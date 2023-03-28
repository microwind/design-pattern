#include "../func.h"

/* DirectSaleShop对象函数实现 */
void direct_sale_shop_greetings(Shop *shop)
{
  printf("\r\n direct_sale_shop_greetings() [name=%s]", shop->name);
}

void direct_sale_shop_welcome()
{
  printf("\r\n direct_sale_shop_welcome().");
}

/* 创建对象构造函数 */
DirectSaleShop *direct_sale_shop_constructor(char *name)
{
  DirectSaleShop *direct_sale_shop = (DirectSaleShop *)malloc(sizeof(DirectSaleShop));
  strncpy(direct_sale_shop->name, name, 50);
  direct_sale_shop->greetings = &direct_sale_shop_greetings;
  direct_sale_shop->welcome = &direct_sale_shop_welcome;
  return direct_sale_shop;
}