#include <stdio.h>

// 纯函数：不依赖于外部状态，且无副作用
// 纯函数接收参数并返回结果，不修改任何外部状态
int add(int a, int b) {
    return a + b;
}

// 高阶函数：接收函数作为参数或者返回一个函数
int functionWithFunc(int (*fn)(int, int), int x, int y) {
    return fn(x, y);  // 执行传入的函数并返回结果
}

// 匿名函数：C 语言没有直接支持匿名函数，
// 但是可以通过函数指针来实现类似的功能
int multiplyFunc(int x, int y) { return x * y; }

int main() {
    int a = 5, b = 3;

    // 调用纯函数
    printf("The sum of %d and %d is: %d\n", a, b, add(a, b));

    // 高阶函数示例
    int sum = functionWithFunc(add, a, b);  // 将 add 函数传入作为高阶函数参数
    printf("The sum calculated by high-order function is: %d\n", sum);

    // 匿名函数示例：C 语言没有直接支持匿名函数
    int (*multiply)(int, int) = multiplyFunc; // 用函数指针模拟匿名函数
    int result = multiply(a, b);  // 调用匿名函数，计算乘积
    printf("The product of %d and %d is: %d\n", a, b, result);

    // 函数式编程的链式调用：需要显式地分步骤
    int resultChain = 5 + 10;
    resultChain = resultChain * 2;
    printf("Chained result: %d\n", resultChain);

    return 0;
}

/*
jarry@MacBook-Pro c % gcc functional.c 
jarry@MacBook-Pro c % ./a.out 
The sum of 5 and 3 is: 8
The sum calculated by high-order function is: 8
The product of 5 and 3 is: 15
Chained result: 30
*/