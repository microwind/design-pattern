import java.util.function.IntBinaryOperator;

public class Functional {

  // 纯函数：不依赖于外部状态，且无副作用
  // 纯函数接收参数并返回结果，不修改任何外部状态
  public static int add(int a, int b) {
      return a + b;
  }

  // 高阶函数：接收函数作为参数或者返回一个函数
  public static int functionWithFunc(IntBinaryOperator fn, int x, int y) {
      return fn.applyAsInt(x, y); // 执行传入的函数并返回结果
  }

  public static void main(String[] args) {
      int a = 5, b = 3;

      // 调用纯函数
      System.out.println("The sum of " + a + " and " + b + " is: " + add(a, b));

      // 高阶函数示例
      int sum = functionWithFunc((x, y) -> x + y, a, b); // 将 add 函数传入作为高阶函数参数
      System.out.println("The sum calculated by high-order function is: " + sum);

      // 匿名函数示例：Java 中使用 Lambda 表达式实现匿名函数
      int result = ((IntBinaryOperator) (x, y) -> x * y).applyAsInt(a, b);  // 调用匿名函数，计算乘积
      System.out.println("The product of " + a + " and " + b + " is: " + result);

      // 函数式编程的链式调用
      int resultChain = ((java.util.function.IntUnaryOperator) (x -> x + 10)).applyAsInt(5);
      resultChain = ((java.util.function.IntUnaryOperator) (x -> x * 2)).applyAsInt(resultChain);
      System.out.println("Chained result: " + resultChain);
  }
}

/*
jarry@MacBook-Pro java % java Functional.java 
The sum of 5 and 3 is: 8
The sum calculated by high-order function is: 8
The product of 5 and 3 is: 15
Chained result: 30
 */