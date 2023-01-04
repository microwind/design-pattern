package src;

// 抽象表达式接口，根据业务场景规范表达式
public interface Expression {
  public int interpret(Context context);
}