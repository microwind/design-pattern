package test;

import src.*;

public class Test {

  public static void start() {

    /**
     * 测试不符合组合复用的例子
     */
    Employee_violate employee = new Employee_violate();
    Employee_violate.Employee engineer = employee.new Engineer("Tom", 25, 1001, "senior engineer");
    engineer.work();
    Employee_violate.Employee manager = employee.new Manager("Jerry", 45, 2002, "advanced director");
    manager.work();

    // *********************** 分割线 ******************************************/
    System.out.println("***********************");

    /**
     * 测试符合组合复用原则的例子
     */
    Employee engineer2 = new Engineer(1001, "senior engineer", new Person("Tom", 25));
    engineer2.work();
    Employee manager2 = new Manager(2002, "advanced director", new Person("Jerry", 45));
    manager2.work();
  }

  public static void main(String[] args) {
    System.out.println("test start:");
    start();
  }

}

/**
 * 测试
 * jarry@jarrys-MacBook-Pro java % javac -encoding utf-8 test/Test.java
 * jarry@jarrys-MacBook-Pro java % java test/Test
 * test start:
 * Engineer is working. id = 1001, title = senior engineer name = Tom, age = 25
 * Manager is working. id = 2002, title = advanced director name = Jerry, age =
 * 45
 ***********************
 * Engineer is working. id = 1001, title = senior engineer name = Tom, age = 25
 * Manager is working. id = 2002, title = advanced director name = Jerry, age =
 * 45
 */