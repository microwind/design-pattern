package src;

public class ContextDog extends Context {

  public ContextDog() {
    // 使用某个策略
    System.out.println("ContextDog::setStrategy(StrategyB).");
    this.setStrategy(new StrategyB());
  }

  // 这样就是强制绑定了策略动作，不够灵活
  // @Override
  // public void action() {
  //   new StrategyC().run();
  // }

}