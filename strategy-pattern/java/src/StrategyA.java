package src;
// 具体策略A
public class StrategyA implements Strategy {
 
  @Override
  public void run() {
     System.out.println("StrategyA::run().");
  }
}