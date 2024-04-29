#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../src/func.h"

int main(void)
{
    printf("test start:\r\n");
    /**
     * 工厂模式由工厂类提供统一的创建对象的方法，省去直接new，而是通过统一方法来创建。
     * 这样的好处就是让对象创建和调用解耦，便于在创建对象时统一干预。
     */

    VehicleFactory *vehicle_factory = create_vehicle_factory();

    // 获取Bus对象，并调用它的 run 方法
    Vehicle *bus = vehicle_factory->get_vehicle("bus");
    ((Bus *)bus)->run();

    // 获取Car对象，并调用它的 run 方法
    Vehicle *car = vehicle_factory->get_vehicle("car");
    ((Car *)car)->run();

    // 获取Motorcycle对象，并调用它的 run 方法
    Vehicle *motorcycle = vehicle_factory->get_vehicle("motorcycle");
    ((Motorcycle *)motorcycle)->run();

    // 获取Van对象，并调用它的 run 方法
    Vehicle *van = vehicle_factory->get_vehicle("van");
    ((Van *)van)->run();

    // 释放内存
    free(vehicle_factory);
    free(bus);
    free(car);
    free(motorcycle);
    free(van);

    return 0;
}


// jarry@jarrys-MacBook-Pro c % gcc test/*.c src/*.c
// jarry@jarrys-MacBook-Pro c % ./a.out
/**
test start:
bus_run(). 
car_run().
motorcycle_run(). 
van_run(). 
 */