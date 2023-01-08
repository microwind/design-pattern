package src;

// 具体的状态实现者，
public class ConcreteStateOn implements State {

  // 策略模式与状态模式都是将策略/状态绑定到执行对象(Context)上
  // 不同的是策略模式是客户可设定策略，而状态则是通过状态动作来实现改变
  @Override
  public void on(Context context) {
    // 当前是on状态，再点击on只是提示，不切换状态类
    System.out.println(this.getClass().getSimpleName() + "::on() [needn't switch, state is ON.]");
  }

  @Override
  public void off(Context context) {
    // 状态变为off后，状态类切换到ConcreteStateOff
    System.out.println(this.getClass().getSimpleName() + "::off() [turn OFF ok!]");
    context.setState(new ConcreteStateOff());
  }

}