# -*- coding: utf-8 -*-
'''
封装即隐藏对象的属性和实现细节，只对外公开必要的接口，控制属性的读写访问级别。
本示例：
- balance是私有属性，外部无法直接访问。确保账户的余额只能通过deposit和withdraw方法来改变。这种封装机制确保了数据的安全性和完整性。
- 公共接口：类提供了一些公共方法，允许外界与对象交互。例如，存款和取款的方法，以及获取余额的方法。这些公共接口定义了与对象交互的规则，而不会暴露内部实现细节。
- 数据验证：在存款和取款的方法中，进行了验证以确保操作的有效性。这种验证有助于维护对象的状态和逻辑的一致性。
'''


class BankAccount:
    def __init__(self, initial_balance):
        if initial_balance >= 0:
            self.balance = initial_balance  # 初始化余额
        else:
            raise ValueError("初始余额不能是负数")

    def deposit(self, amount):
        if amount > 0:
            self.balance += amount  # 增加余额
        else:
            print("存款金额必须大于零")

    def withdraw(self, amount):
        if 0 < amount <= self.balance:
            self.balance -= amount  # 减少余额
        else:
            print("取款金额无效")

    def get_balance(self):
        return self.balance  # 返回余额


# 创建一个银行账户，初始余额为100
my_account = BankAccount(100)

# 进行存款
my_account.deposit(50)  # 存款50
print("Balance:", my_account.get_balance())  # 输出：Balance: 150

# 进行取款
my_account.withdraw(30)  # 取款30
print("Balance:", my_account.get_balance())  # 输出：Balance: 120

# 尝试取款超出余额
my_account.withdraw(200)  # 输出：取款金额无效
