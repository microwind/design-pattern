package src;
public class ContextCat extends Context {
 
  public ContextCat() {
    // 使用某个策略
    System.out.println("ContextCat::setStrategy(StrategyC).");
    this.setStrategy(new StrategyC());
  }
}