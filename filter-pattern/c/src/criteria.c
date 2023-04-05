#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

/* Criterial是条件的抽象接口，聚合要过滤的对象集合 */

// c语言没有抽象类或接口，Criterial作为基础struct定义在head， 这里放一些公共函数

char *str_toupper(char str[])
{
    int size = strlen(str);
    char *result = (char *)malloc(size * sizeof(char));
    int i = 0;
    while (str[i])
    {
        result[i] = toupper(str[i]);
        i++;
    }

    return result;
}

char *str_tolower(char str[])
{
    int size = strlen(str);
    char *result = (char *)malloc(size * sizeof(char));
    int i = 0;
    while (str[i])
    {
        result[i] = tolower(str[i]);
        i++;
    }

    return result;
}
