package src;

// 具体表达式，实现了抽象表达式接口
public class AddExpression implements Expression {

    private Expression exprOne = null;
    private Expression exprTwo = null;

    public AddExpression(Expression exprOne, Expression exprTwo) {
        this.exprOne = exprOne;
        this.exprTwo = exprTwo;
    }

    // 覆盖表达式，执行context对象
    @Override
    public int interpret(Context context) {
        System.out.println(this.getClass().getName() + "::interpret() [context = " + context.getClass().getName() + "]");
        return exprOne.interpret(context) + exprTwo.interpret(context);
    }
}