/* 
封装即隐藏对象的属性和实现细节，只对外公开必要的接口，控制属性的读写访问级别。
本示例：
- balance是私有属性，外部无法直接访问。确保账户的余额只能通过deposit和withdraw方法来改变。这种封装机制确保了数据的安全性和完整性。
- 公共接口：类提供了一些公共方法，允许外界与对象交互。例如，存款和取款的方法，以及获取余额的方法。这些公共接口定义了与对象交互的规则，而不会暴露内部实现细节。
- 数据验证：在存款和取款的方法中，进行了验证以确保操作的有效性。这种验证有助于维护对象的状态和逻辑的一致性。
*/

// 定义一个银行账户类
class BankAccount {
  // 私有属性，表示银行账户的余额
  private double balance;

  // 构造方法，用于初始化账户余额
  public BankAccount(double initialBalance) {
      if (initialBalance >= 0) {
          this.balance = initialBalance;  // 初始化余额
      } else {
          throw new IllegalArgumentException("初始余额不能是负数");
      }
  }

  // 公共方法，存款
  public void deposit(double amount) {
      if (amount > 0) {
          balance += amount;  // 增加余额
      } else {
          System.out.println("存款金额必须大于零");
      }
  }

  // 公共方法，取款
  public void withdraw(double amount) {
      if (amount > 0 && amount <= balance) {
          balance -= amount;  // 减少余额
      } else {
          System.out.println("取款金额无效");
      }
  }

  // 公共方法，获取当前余额
  public double getBalance() {
      return balance;  // 返回余额
  }
}

// 测试验证
public class EncapsulationExample {
  public static void main(String[] args) {
      // 创建一个银行账户，初始余额为100
      BankAccount myAccount = new BankAccount(100);

      // 进行存款
      myAccount.deposit(50);  // 存款50
      System.out.println("Balance: " + myAccount.getBalance());  // 输出：Balance: 150

      // 进行取款
      myAccount.withdraw(30);  // 取款30
      System.out.println("Balance: " + myAccount.getBalance());  // 输出：Balance: 120

      // 尝试直接访问私有属性（编译时会报错）
      // myAccount.balance = 200;  // 错误：无法访问私有属性

      // 尝试取款超出余额
      myAccount.withdraw(200);  // 输出：取款金额无效
  }
}