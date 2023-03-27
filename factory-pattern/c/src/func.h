#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 基础对象
typedef struct Vehicle
{
    // char name[50];
    // void (*run)();
} Vehicle;

// Bus对象
typedef struct Bus
{
    char name[50];
    void (*run)();
} Bus;

// Bus构造函数
Bus *bus_constructor(char *name);

// Car对象
typedef struct Car
{
    char name[50];
    void (*run)();
} Car;

// Car构造函数
Car *car_constructor(char *name);

// Motorcycle对象
typedef struct Motorcycle
{
    char name[50];
    void (*run)();
} Motorcycle;

// Motorcycle构造函数
Motorcycle *motorcycle_constructor(char *name);

// Van对象
typedef struct Van
{
    char name[50];
    void (*run)();
} Van;

// Van构造函数
Van *van_constructor(char *name);

// 对象工厂
typedef struct VehicleFactory
{
    Vehicle *(*get_vehicle)(char *type);
} VehicleFactory;

VehicleFactory *create_vehicle_factory();
