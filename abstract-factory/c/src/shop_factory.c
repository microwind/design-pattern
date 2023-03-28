#include "func.h"

/* shop_factory实现 */

// 获取商店工厂
Shop *get_shop(int type, char *name)
{
  switch (type)
  {
  case AGENCY_SHOP_TYPE:
    return (Shop *)agency_shop_constructor(name);
  case DIRECT_SALE_SHOP_TYPE:
    return (Shop *)direct_sale_shop_constructor(name);
  case SUPERMARKET_SHOP_TYPE:
    return (Shop *)supermarket_shop_constructor(name);
  default:
    break;
  }
  return NULL;
}

/* 创建具体工厂的函数 */
ShopFactory *create_shop_factory()
{
  ShopFactory *factory = (ShopFactory *)malloc(sizeof(ShopFactory));
  factory->get_shop = &get_shop;
  factory->get_vehicle = NULL;
  return factory;
}