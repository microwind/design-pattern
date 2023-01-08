package src;

// 具体的状态实现者
public class ConcreteStateOff implements State {

  @Override
  public void on(Context context) {
    System.out.println(this.getClass().getSimpleName() + "::on() [turn ON ok!]");
    // 状态变为on后，状态类切换到ConcreteStateOn
    context.setState(new ConcreteStateOn());
  }

  @Override
  public void off(Context context) {
    // 当前是off状态，再点击off只是提示，不切换状态类
    System.out.println(this.getClass().getSimpleName() + "::off() [needn't switch, state is OFF.]");
  }

}