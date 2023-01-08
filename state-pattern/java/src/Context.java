package src;

// 执行实体类，内部关联状态
public class Context {
  private State state;

  public Context(State state) {
    this.state = state;
  }

  public Context() {
  }

  public State getState() {
    return state;
  }

  public void setState(State state) {
    System.out
        .println(this.getClass().getSimpleName() + "::setState() [state = " + state.getClass().getSimpleName() + "]");
    this.state = state;
  }

  public void turnOn() {
    state.on(this);
  }

  public void turnOff() {
    state.off(this);
  }
}
