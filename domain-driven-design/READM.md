# DDD 分层架构设计概述

领域驱动设计（Domain-Driven Design，简称 DDD）是一种软件架构方法，旨在通过分层和领域建模的方式来管理复杂业务逻辑。DDD 主要通过分层架构来组织代码，以实现高内聚、低耦合。

## DDD 结构图形示例

```
+---------------------+
|   用户界面（UI）   |
+---------▲-----------+
          |
+---------|-----------+
| 应用服务层（Application Service）|
+---------▲-----------+
          |
+---------|-----------+
|       领域层（Domain）       |
+---------▲-----------+
          |
+---------|-----------+
| 基础设施层（Infrastructure）|
+---------------------+
```

### 各层职责
- **用户界面（UI）层**：处理用户输入与展示信息。
- **应用服务层**：定义应用程序的用例，协调领域层的操作。
- **领域层**：实现核心业务逻辑，包括实体、值对象、聚合、领域服务等。
- **基础设施层**：提供数据库、外部 API、消息队列等技术支持。

## DDD 分层架构与 MVX 分层架构的对比

| 特性       | MVX（MVC/MVP/MVVM） | DDD（领域驱动设计） |
|------------|---------------------|---------------------|
| 主要目标   | 分离 UI、业务逻辑和数据 | 解决复杂领域建模与业务逻辑 |
| 关注点     | UI 驱动，适用于前端开发 | 领域驱动，适用于复杂业务系统 |
| 层次       | 3 层（Model、View、X） | 4 层（UI、应用、领域、基础设施） |
| 适用场景   | 前端框架、简单应用     | 企业级系统、复杂业务领域 |

## DDD 的应用场景

- **企业级系统**，如电商平台、ERP、银行系统。
- **业务逻辑复杂**，需要清晰的领域建模。
- **多个系统交互**，涉及数据库、外部 API、消息队列等。
- **团队协作开发**，需要业务人员和开发人员紧密合作。

## DDD 的例子（C、Java、JavaScript、Go）

### C 语言实现 DDD
```c
#include <stdio.h>
#include <string.h>

// 领域层
typedef struct {
    char name[50];
    double balance;
} Account;

void deposit(Account *account, double amount) {
    account->balance += amount;
}

// 应用服务层
void processDeposit(Account *account, double amount) {
    deposit(account, amount);
}

// UI 层
int main() {
    Account acc = {"Alice", 1000};
    processDeposit(&acc, 500);
    printf("%s 的余额: %.2f\n", acc.name, acc.balance);
    return 0;
}
```

### Java 语言实现 DDD
```java
// 领域层
class Account {
    private String name;
    private double balance;

    public Account(String name, double balance) {
        this.name = name;
        this.balance = balance;
    }

    public void deposit(double amount) {
        balance += amount;
    }

    public double getBalance() {
        return balance;
    }
}

// 应用服务层
class AccountService {
    public void deposit(Account account, double amount) {
        account.deposit(amount);
    }
}

// UI 层
public class Main {
    public static void main(String[] args) {
        Account account = new Account("Alice", 1000);
        AccountService service = new AccountService();
        service.deposit(account, 500);
        System.out.println("Alice 的余额: " + account.getBalance());
    }
}
```

### JavaScript 语言实现 DDD
```javascript
// 领域层
class Account {
    constructor(name, balance) {
        this.name = name;
        this.balance = balance;
    }
    deposit(amount) {
        this.balance += amount;
    }
}

// 应用服务层
class AccountService {
    deposit(account, amount) {
        account.deposit(amount);
    }
}

// UI 层
const account = new Account("Alice", 1000);
const service = new AccountService();
service.deposit(account, 500);
console.log(`Alice 的余额: ${account.balance}`);
```

### Go 语言实现 DDD
```go
package main

import "fmt"

// 领域层
type Account struct {
    Name    string
    Balance float64
}

func (a *Account) Deposit(amount float64) {
    a.Balance += amount
}

// 应用服务层
type AccountService struct{}

func (s *AccountService) Deposit(account *Account, amount float64) {
    account.Deposit(amount)
}

// UI 层
func main() {
    account := &Account{Name: "Alice", Balance: 1000}
    service := &AccountService{}
    service.Deposit(account, 500)
    fmt.Printf("%s 的余额: %.2f\n", account.Name, account.Balance)
}
```

## 总结
- **DDD 适用于复杂业务系统**，强调领域建模和高内聚低耦合。
- **MVX 适用于 UI 结构清晰的前端应用**，重点在于 UI 与业务逻辑的分离。
- **不同语言都可以实现 DDD**，关键是遵循分层架构原则。
