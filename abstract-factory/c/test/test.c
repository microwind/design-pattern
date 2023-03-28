#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../src/func.h"

int main(void)
{
    printf("test start:\r\n");
    /**
     * 抽象工厂就是把生产产品的工厂也根据统一的抽象工厂来创建，
     * 这样不同类型的工厂可以在统一的约束下，整体上看更新加清晰。
     * 当声明工厂时可以通过抽象类型或具体工厂来声明，然后依据工厂来生产不同的产品。
     */

    // 初始化工厂制造者
    FactoryCreatory *factory_creatory = factory_creatory_constructor();

    // 声明一个汽车工厂
    AbstractFactory *vehicle_factory = factory_creatory->get_factory("vehicle");
    // 从汽车工厂获取Bus对象，并调用它的 run 方法
    Vehicle *bus = vehicle_factory->get_vehicle("bus", "bus_01");
    ((Bus *)bus)->run(bus);

    // 获取Car对象，类型强转，并调用它的 run 方法
    Vehicle *car = vehicle_factory->get_vehicle("car", "car_01");
    Car *car1 = (Car *)car;
    car1->run(car);

    /*********************** 分割线 ******************************************/

    // 声明商店工厂
    AbstractFactory *shop_factory = factory_creatory->get_factory("shop");
    // 从商店工厂获取商店对象
    Shop *shop = shop_factory->get_shop(3, "supermarket_shop_02");
    // 调用商店的方法
    ((SupermarketShop *)shop)->greetings(shop);

    // 声明时类型强转
    AgencyShop *agency_shop = ((AgencyShop *)shop_factory->get_shop(1, "agency_shop_02"));
    // 调用商店的方法
    agency_shop->greetings((Shop *)agency_shop);

    /*********************** 分割线 ******************************************/

    // 再声明一个商店工厂
    AbstractFactory *shop_factory2 = factory_creatory->get_factory("shop");
    Shop *direct_sale_shop = shop_factory2->get_shop(2, "direct_sale_shop_03");
    ((DirectSaleShop *)direct_sale_shop)->greetings(direct_sale_shop);
    // Shop结构体没有添加welcome函数，故无法直接调用
    // direct_sale_shop->welcome();

    // 类型转换测试，将Shop接口类强转为DirectSaleShop实现类
    DirectSaleShop *direct_sale_shop2 = (DirectSaleShop *)direct_sale_shop;
    direct_sale_shop2->greetings((Shop *)direct_sale_shop2);
    // 通过类型转换就可以调用welcome
    direct_sale_shop2->welcome();

    // 释放内存
    free(factory_creatory);
    free(vehicle_factory);
    free(bus);
    free(car);
    free(shop);
    free(agency_shop);
    free(direct_sale_shop);
    free(shop_factory);
    free(shop_factory2);

    return 0;
}

/**
jarry@jarrys-MacBook-Pro c % gcc src/**/
*.c test /*.c
jarry@jarrys-MacBook-Pro c % ./a.out
test start:

bus_run() [name=bus_01]
car_run() [name=car_01]
supermarket_shop_greetings() [name=supermarket_shop_02]
agency_shop_greetings() [name=agency_shop_02]
direct_sale_shop_greetings() [name=direct_sale_shop_03]
direct_sale_shop_greetings() [name=direct_sale_shop_03]
direct_sale_shop_welcome().%
*/