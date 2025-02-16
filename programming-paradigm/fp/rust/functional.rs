fn main() {
  // 纯函数：不依赖于外部状态，且无副作用
  // 纯函数接收参数并返回结果，不修改任何外部状态
  fn add(a: i32, b: i32) -> i32 {
      a + b
  }

  // 高阶函数：接收函数作为参数或者返回一个函数
  fn function_with_func<F>(fn_param: F, x: i32, y: i32) -> i32
  where
      F: Fn(i32, i32) -> i32,
  {
      fn_param(x, y) // 执行传入的函数并返回结果
  }

  // 变量赋值
  let a = 5;
  let b = 3;

  // 调用纯函数
  println!("The sum of {} and {} is: {}", a, b, add(a, b));

  // 高阶函数示例
  let sum = function_with_func(add, a, b); // 将 add 函数传入作为高阶函数参数
  println!("The sum calculated by high-order function is: {}", sum);

  // 匿名函数示例
  let result = |x: i32, y: i32| x * y;
  println!("The product of {} and {} is: {}", a, b, result(a, b));

  // 函数式编程的链式调用
  let result_chain = (|a: i32| a + 10)(5);
  let result_chain = (|a: i32| a * 2)(result_chain);
  println!("Chained result: {}", result_chain);
}

/*
jarry@Mac rust % ./functional 
The sum of 5 and 3 is: 8
The sum calculated by high-order function is: 8
The product of 5 and 3 is: 15
Chained result: 30
*/