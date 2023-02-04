package src;
// 具体策略C
public class StrategyC implements Strategy {
 
  @Override
  public void run() {
     System.out.println("StrategyC::run().");
  }
}