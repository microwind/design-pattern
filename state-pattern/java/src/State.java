package src;

// 定义状态接口和状态方法，当前context只有一种状态
public interface State {
  public void on(Context context);
  public void off(Context context);
}