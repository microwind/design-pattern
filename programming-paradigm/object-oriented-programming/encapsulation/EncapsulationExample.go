/*
封装即隐藏对象的属性和实现细节，只对外公开必要的接口，控制属性的读写访问级别。
本示例：
- balance是私有属性，外部无法直接访问。确保账户的余额只能通过deposit和withdraw方法来改变。这种封装机制确保了数据的安全性和完整性。
- 公共接口：类提供了一些公共方法，允许外界与对象交互。例如，存款和取款的方法，以及获取余额的方法。这些公共接口定义了与对象交互的规则，而不会暴露内部实现细节。
- 数据验证：在存款和取款的方法中，进行了验证以确保操作的有效性。这种验证有助于维护对象的状态和逻辑的一致性。
*/

package main

import "fmt"

// 定义银行账户结构体
type BankAccount struct {
    balance float64 // 银行账户的余额
}

// 创建银行账户的函数
func createBankAccount(initialBalance float64) *BankAccount {
    if initialBalance >= 0 {
        return &BankAccount{initialBalance}
    } else {
        fmt.Println("初始余额不能是负数")
        return nil
    }
}

// 存款的方法
func (account *BankAccount) deposit(amount float64) {
    if amount > 0 {
        account.balance += amount
    } else {
        fmt.Println("存款金额必须大于零")
    }
}

// 取款的方法
func (account *BankAccount) withdraw(amount float64) {
    if amount > 0 && amount <= account.balance {
        account.balance -= amount
    } else {
        fmt.Println("取款金额无效")
    }
}

// 获取当前余额的方法
func (account *BankAccount) getBalance() float64 {
    return account.balance
}

func main() {
    // 创建一个银行账户，初始余额为100
    myAccount := createBankAccount(100)

    // 进行存款
    myAccount.deposit(50)                           // 存款50
    fmt.Println("Balance:", myAccount.getBalance()) // 输出：Balance: 150

    // 进行取款
    myAccount.withdraw(30)                          // 取款30
    fmt.Println("Balance:", myAccount.getBalance()) // 输出：Balance: 120

    // 尝试取款超出余额
    myAccount.withdraw(200) // 输出：取款金额无效
}
