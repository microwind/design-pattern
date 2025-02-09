# 纯函数：不依赖于外部状态，且无副作用
# 纯函数接收参数并返回结果，不修改任何外部状态
def add(a, b):
    return a + b

# 高阶函数：接收函数作为参数或者返回一个函数
def function_with_func(fn, x, y):
    return fn(x, y)  # 执行传入的函数并返回结果

# 匿名函数：没有名称的函数，可以直接在代码中传递和调用
a, b = 5, 3
print(f"The sum of {a} and {b} is: {add(a, b)}")  # 调用纯函数

# 高阶函数示例
sum_result = function_with_func(add, a, b)  # 将 add 函数传入作为高阶函数参数
print(f"The sum calculated by high-order function is: {sum_result}")

# 匿名函数示例
result = (lambda x, y: x * y)(a, b)  # 调用匿名函数，计算乘积
print(f"The product of {a} and {b} is: {result}")

# 函数式编程的链式调用
result_chain = (lambda a: a + 10)(5)
result_chain = (lambda a: a * 2)(result_chain)
print(f"Chained result: {result_chain}")

"""
jarry@MacBook-Pro python % python functional.py 
The sum of 5 and 3 is: 8
The sum calculated by high-order function is: 8
The product of 5 and 3 is: 15
Chained result: 30
"""