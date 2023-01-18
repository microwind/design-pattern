package test;

import src.*;
import java.util.*;

public class Test {

  public static void start() {

    /**
     * 过滤器模式就是不断组合过滤条件，然后层层过滤的模式
     * 这里是简单演示，用List筛选来模拟过滤，实际例子有各种数据结构
     */
    List<Person> persons = new ArrayList<Person>();

    persons.add(new Person("王男单", "Male", "Single"));
    persons.add(new Person("李男婚", "Male", "Married"));
    persons.add(new Person("张女婚", "Female", "Married"));
    persons.add(new Person("赵女单", "Female", "Single"));
    persons.add(new Person("刘男单", "Male", "Single"));
    persons.add(new Person("杨男单", "Male", "Single"));

    Criteria male = new CriteriaMale();
    Criteria female = new CriteriaFemale();
    Criteria single = new CriteriaSingle();
    Criteria singleMale = new AndCriteria(single, male);
    Criteria singleOrFemale = new OrCriteria(single, female);

    // 查询男性
    System.out.println("Males: ");
    printPersons(male.filter(persons));

    // 查询女性
    System.out.println("\nFemales: ");
    printPersons(female.filter(persons));

    // 嵌套查询女性且单身
    System.out.println("\nFemales and Single: ");
    printPersons(single.filter(female.filter(persons)));

    // 查询男性男性单身
    System.out.println("\nSingle Males: ");
    printPersons(singleMale.filter(persons));

    // 查询女性或单身
    System.out.println("\nSingle Or Females: ");
    printPersons(singleOrFemale.filter(persons));

  }

  public static void printPersons(List<Person> persons) {
    for (Person person : persons) {
      System.out.println(person.toString());
    }
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
 * Males:
 * Person : [ Name : 王男单, Gender : Male, Marital Status : Single ]
 * Person : [ Name : 李男婚, Gender : Male, Marital Status : Married ]
 * Person : [ Name : 刘男单, Gender : Male, Marital Status : Single ]
 * Person : [ Name : 杨男单, Gender : Male, Marital Status : Single ]
 * 
 * Females:
 * Person : [ Name : 张女婚, Gender : Female, Marital Status : Married ]
 * Person : [ Name : 赵女单, Gender : Female, Marital Status : Single ]
 * 
 * Females and Single:
 * Person : [ Name : 赵女单, Gender : Female, Marital Status : Single ]
 * 
 * Single Males:
 * Person : [ Name : 王男单, Gender : Male, Marital Status : Single ]
 * Person : [ Name : 刘男单, Gender : Male, Marital Status : Single ]
 * Person : [ Name : 杨男单, Gender : Male, Marital Status : Single ]
 * 
 * Single Or Females:
 * Person : [ Name : 王男单, Gender : Male, Marital Status : Single ]
 * Person : [ Name : 赵女单, Gender : Female, Marital Status : Single ]
 * Person : [ Name : 刘男单, Gender : Male, Marital Status : Single ]
 * Person : [ Name : 杨男单, Gender : Male, Marital Status : Single ]
 * Person : [ Name : 张女婚, Gender : Female, Marital Status : Married ]
 */