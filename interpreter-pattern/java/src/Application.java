package src;

public class Application {

   // 构建两个数相加的例子
   public static int addTwo(int one, int two) {
      // 构建执行上下文环境
      Context context = new Context();
      context.add("one", one);
      context.add("two", two);

      // 构建表达式
      VarExpression varOne = new VarExpression("one");
      VarExpression varTwo = new VarExpression("two");

      // 再构建变量来进行计算，看起来啰嗦，但这样构建多种不同表达式计算就变得简单
      Expression result = new AddExpression(varOne, varTwo);
      return result.interpret(context);
   }

   // 构建连加计算的例子
   public static int addMore(int... numbers) {
      if (numbers.length <= 1) {
         return numbers[0];
      }

      Context context = new Context();
      // 构建执行环境
      for (int num : numbers) {
         context.add("num" + num, num);
      }

      // 先取出前两个作为计算基础
      VarExpression varOne = new VarExpression("num" + numbers[0]);
      VarExpression varTwo = new VarExpression("num" + numbers[1]);
      // 再构建表达式，先赋值前两个
      Expression expression = new AddExpression(varOne, varTwo);

      // 如果只有数则则直接返回结果
      if (numbers.length == 2) {
         return expression.interpret(context);
      }

      // 如果数量超过两个则累加表达式再求值
      for (int i = 2; i < numbers.length; i++) {
         Expression nextExpression = new VarExpression("num" + numbers[i]);
         // 表达式不断累加
         expression = new AddExpression(expression, nextExpression);
      }

      return expression.interpret(context);
   }

   // 计算前两个数相加，再减去后一个数的计算例子
   public static int addAndSubtract(int one, int two, int three) {
      // 构建执行上下文环境，有3个可操作的域
      Context context = new Context();
      context.add("one", one);
      context.add("two", two);
      context.add("three", three);

      // 构建表达式，有3个变量
      VarExpression varOne = new VarExpression("one");
      VarExpression varTwo = new VarExpression("two");
      VarExpression varThree = new VarExpression("three");


      // 再构建计算步骤，前两个用减法
      Expression result = new AddExpression(varOne, varTwo);
      result = new SubtractExpression(result, varThree);
      // 第3个用减法
      return result.interpret(context);
   }
}