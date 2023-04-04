#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 外观模式的接口或抽象类，可选
typedef struct AbstractFacade
{
    char name[50];
    void (*encoding)(struct AbstractFacade *, int);
    void (*encrypt)(struct AbstractFacade *, int);
    struct FileModule *file_module;
    struct NetworkModule *network_module;
    struct EncodeModule *encode_module;
} AbstractFacade;

// 外观模式实现类，是外部调用与内部子系统的衔接层
typedef struct Facade
{
    char name[50];
    void (*encoding)(struct Facade *, int);
    void (*encrypt)(struct Facade *, int);
    struct FileModule *file_module;
    struct NetworkModule *network_module;
    struct EncodeModule *encode_module;
} Facade;
Facade *facade_constructor(char *name);

typedef struct EncodeModule
{
    char name[50];
    void (*encoding)();
} EncodeModule;
EncodeModule *encode_module_constructor(char *name);

typedef struct FileModule
{
    char name[50];
    void (*read_file)();
    void (*save_file)();
} FileModule;
FileModule *file_module_constructor(char *name);

typedef struct NetworkModule
{
    char name[50];
    void (*request)();
} NetworkModule;
NetworkModule *network_module_constructor(char *name);
