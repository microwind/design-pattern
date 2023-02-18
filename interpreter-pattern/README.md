# 【解释器设计模式详解】Java/JS/Go/Python/TS不同语言实现

# 简介
解释器模式（Interpreter Pattern）是一种行为型设计模式。这种模式实现了一个表达式接口，该接口解释一个特定的上下文。这种模式常被用在 SQL 解析、符号处理引擎等。

解释器模式常用于对简单语言的编译或分析实例中，为了掌握好它的结构与实现，必须先了解编译原理中的“文法、句子、语法树”等相关概念。

# 作用
1. 可扩展性比较好，灵活，增加了新的解释表达式的方式，易于实现简单文法。
2. 在语法树中的每个表达式节点类都是相似的，所以实现其文法较为容易。

# 实现步骤
1. 创建抽象表达式接口（Expression），各种表达式都要实现该接口。
2. 分别创建最终表达式和非最终表达式。最终表达式（这里是VarExpression）没有子级，直接解释表达式。非最终表达式（这里是AddExpression和SubtractExpression）是维护子表达式的容器，并将解释请求转发给这些表达式。
3. 创建上下文环境类（这里是Context），用来表达式求值时构建执行环境。
4. 客户端调用时先建立执行上下文环境，然后声明变量，再进行计算。

# UML
<img src="../docs/uml/interpreter-pattern.png">

# 代码

## 抽象表达式接口
```java
// Expression.java 抽象表达式接口，根据业务场景规范表达式
public interface Expression {
  public int interpret(Context context);
}
```

## 具体表达式实现

```java
// AddExpression.java 具体表达式，实现了抽象表达式接口
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
```

```java
// SubtractExpression.java 具体表达式，实现了抽象表达式接口
public class SubtractExpression implements Expression {

  private Expression exprOne = null;
  private Expression exprTwo = null;

  public SubtractExpression(Expression exprOne, Expression exprTwo) {
    this.exprOne = exprOne;
    this.exprTwo = exprTwo;
  }

  // 覆盖表达式，执行context对象
  @Override
  public int interpret(Context context) {
    System.out.println(this.getClass().getName() + "::interpret() [context = " + context.getClass().getName() + "]");
    return exprOne.interpret(context) - exprTwo.interpret(context);
  }
}
```

```java
// VarExpression.java 变量表达式，或者叫终端表达式，其他表达式求值时通过层层追溯最后指向这里
// 变量与执行环境的Key对应，最终会通过key获取传入的值
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
```

## 执行环境类
```java
// Context.java 构建可执行环境上下文
public class Context {

   private Map<String, Integer> map = new HashMap<>();

   public Context(String key, int value) {
      this.add(key, value);
   }

   public Context() {
   }

   public void add(String key, int value) {
      map.put(key, value);
   }

   public int get(String key) {
      return map.get(key);
   }
}
```

## 测试调用
```java
    /*
     * 解释器模式先构建执行上下文Context，然后构建一个最终的获取值的表达式VarExpression，这就构成了含上下文和变量-值的基本环境。
     * 再将基本环境放到工具表达式里AddExpression或SubtractExpreesion进行计算，最终得到结果。
     */
    
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

      // 如果只有两个数则直接返回计算结果
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
```
## 更多语言版本
不同语言实现设计模式：[https://github.com/microwind/design-pattern](https://github.com/microwind/design-pattern)