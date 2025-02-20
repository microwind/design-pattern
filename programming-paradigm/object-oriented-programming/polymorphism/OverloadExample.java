/**
 * 重载示例，同名方法，参数个数或类型不同。
 * 编译器在编译时确定具体的调用方法。
 */
class Calculator {
    public int add(int num1, int num2) {
        return num1 + num2;
    }

    public int add(String num1, String num2) {
        int sum = 0;
        try {
            sum += Integer.parseInt(num1);
            sum += Integer.parseInt(num2);
        } catch (NumberFormatException e) {
            System.out.println("参数不是有效数字。");
            return Integer.MIN_VALUE;
        }
        return sum;
    }

    public int add(int... nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        return sum;
    }
}

public class OverloadExample {
    public static void main(String[] args) {
        Calculator calculator = new Calculator();

        // 调用 add(int, int) 方法
        int result1 = calculator.add(5, 3);
        // 输出: 8
        System.out.println("add(int, int): " + result1);

        // 调用 add(String, String) 方法
        int result2 = calculator.add("4", "6");
        // 输出: 10
        System.out.println("add(String, String): " + result2);

        // 调用 add(int...) 方法
        int result3 = calculator.add(1, 2, 3, 4);
        // 输出: 10
        System.out.println("add(int...): " + result3);

        // 调用 add(String, String) 方法，其中一个字符串不是整数
        int result4 = calculator.add("4", "abc");
        System.out.println("add(String, String) 报错: " + result4);
    }
}
