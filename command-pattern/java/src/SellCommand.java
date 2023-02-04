package src;

// 出售命令，操作receiver，实现了抽象命令类
public class SellCommand implements Command {
  private StockReceiver stockReceiver;

  public SellCommand(StockReceiver stockReceiver) {
    this.stockReceiver = stockReceiver;
  }

  // 命令类调用执行者来的实际动作
  public void execute() {
    System.out.println(this.getClass().getName() + "::execute() ");
    stockReceiver.sell();
  }
}
