/*
封装即隐藏对象的属性和实现细节，只对外公开必要的接口，控制属性的读写访问级别。
本示例：
- balance是私有属性，外部无法直接访问。确保账户的余额只能通过deposit和withdraw方法来改变。这种封装机制确保了数据的安全性和完整性。
- 公共接口：类提供了一些公共方法，允许外界与对象交互。例如，存款和取款的方法，以及获取余额的方法。这些公共接口定义了与对象交互的规则，而不会暴露内部实现细节。
- 数据验证：在存款和取款的方法中，进行了验证以确保操作的有效性。这种验证有助于维护对象的状态和逻辑的一致性。
*/

#include <stdio.h>
#include <stdlib.h>

// 定义银行账户结构体
struct BankAccount
{
    double balance; // 银行账户的余额
};

// 创建银行账户的函数
struct BankAccount *create_bank_account(double initial_balance)
{
    if (initial_balance >= 0)
    {
        struct BankAccount *account = (struct BankAccount *)malloc(sizeof(struct BankAccount));
        account->balance = initial_balance; // 初始化余额
        return account;
    }
    else
    {
        printf("初始余额不能是负数\n");
        exit(1);
    }
}

// 存款的函数
void deposit(struct BankAccount *account, double amount)
{
    if (amount > 0)
    {
        account->balance += amount; // 增加余额
    }
    else
    {
        printf("存款金额必须大于零\n");
    }
}

// 取款的函数
void withdraw(struct BankAccount *account, double amount)
{
    if (amount > 0 && amount <= account->balance)
    {
        account->balance -= amount; // 减少余额
    }
    else
    {
        printf("取款金额无效\n");
    }
}

// 获取当前余额的函数
double get_balance(struct BankAccount *account)
{
    return account->balance; // 返回余额
}

// 主函数
int main()
{
    // 创建一个银行账户，初始余额为100
    struct BankAccount *my_account = create_bank_account(100);

    // 进行存款
    deposit(my_account, 50);                            // 存款50
    printf("Balance: %.2f\n", get_balance(my_account)); // 输出：Balance: 150.00

    // 进行取款
    withdraw(my_account, 30);                           // 取款30
    printf("Balance: %.2f\n", get_balance(my_account)); // 输出：Balance: 120.00

    // 尝试取款超出余额
    withdraw(my_account, 200); // 输出：取款金额无效

    // 释放内存
    free(my_account);

    return 0;
}
