package src;

// 构建变量表达式，变量与执行环境的Key对应
// 变量表达式是可选的，不用VarExpression则可以直接用其他表达式替代
public class VarExpression implements Expression {
  private String key;

  public VarExpression(String key) {
    this.key = key;
  }

  @Override
  // 覆盖表达式，根据key获取变量
  public int interpret(Context context) {
    return context.get(key);
  }
}