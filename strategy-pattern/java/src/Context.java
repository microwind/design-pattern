package src;

// 抽象业务类，聚合策略对象
public abstract class Context {

  protected Strategy strategy;

  public void setStrategy(Strategy strategy) {
    this.strategy = strategy;
  }

  public void action() {
    this.strategy.run();
  }

}