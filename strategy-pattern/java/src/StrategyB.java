package src;
// 具体策略B
public class StrategyB implements Strategy {
 
  @Override
  public void run() {
     System.out.println("StrategyB::run().");
  }
}