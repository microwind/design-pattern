package test;

import src.*;

public class Test {

  public static void start() {
    /**
     * 解释器模式实现了一个表达式接口，该接口可以解释一个特定的上下文的变量和语句。
     * 也就是先定义上下文，然后定义变量，再使用表达式进行求值。相当可以构造一个简单的语法解析器。
     */

    int result1 = Application.addTwo(1, 2);
    System.out.println("result1: " + result1);

    int result2 = Application.addMore(1, 2, 3, 4, 5);
    System.out.println("result2: " + result2);

    int result3 = Application.addAndSubtract(3, 4, 5);
    System.out.println("result3: " + result3);

  }

  public static void main(String[] args) {
    System.out.println("test start:");
    start();
  }
}
/**
 * 测试
 * jarry@jarrys-MacBook-Pro java % javac test/Test.java
 * jarry@jarrys-MacBook-Pro java % java test/Test
 * test start:
 * src.AddExpression::interpret() [context = src.Context]
 * result1: 3
 * src.AddExpression::interpret() [context = src.Context]
 * src.AddExpression::interpret() [context = src.Context]
 * src.AddExpression::interpret() [context = src.Context]
 * src.AddExpression::interpret() [context = src.Context]
 * result2: 15
 * src.SubtractExpression::interpret() [context = src.Context]
 * src.AddExpression::interpret() [context = src.Context]
 * result3: 2
 */
