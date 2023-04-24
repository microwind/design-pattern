#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Image Image;
typedef struct ProxyImage ProxyImage;
typedef struct RealImage RealImage;

// 定义一个接口供代理和实际调用来使用
typedef struct Image
{
    char file_name[200];
    RealImage *real_image;
    void (*set_file_name)(Image *image, char *file_name);
    void (*display)(Image *image);
} Images;

void image_set_file_name(Image *image, char *file_name);

// 代理类也实现了基础接口
typedef struct ProxyImage
{
    char file_name[200];
    // 代理类聚合真实类
    RealImage *real_image;
    void (*set_file_name)(ProxyImage *image, char *file_name);
    void (*display)(ProxyImage *image);
} ProxyImage;
ProxyImage *proxy_image_constructor(char *file_name);

// 真实类实现基础接口
typedef struct RealImage
{
    char file_name[200];
    RealImage *real_image;
    void (*set_file_name)(RealImage *image, char *file_name);
    void (*display)(RealImage *image);
} RealImage;
RealImage *real_image_constructor(char *file_name);
void real_image_init(RealImage *image, char *file_name);