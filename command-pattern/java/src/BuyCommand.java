package src;

// 购买命令，操作receiver，实现了抽象命令类
public class BuyCommand implements Command {
  private StockReceiver stockReceiver;

  public BuyCommand(StockReceiver stockReceiver) {
    this.stockReceiver = stockReceiver;
  }

  // 命令类调用执行者的实际动作
  public void execute() {
    System.out.println(this.getClass().getName() + "::execute() ");
    this.stockReceiver.buy();
  }
}