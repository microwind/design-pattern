package src;

/**
 * 雇员抽象类，供其他角色继承
 * 聚合了人物类
 */
public abstract class Employee {
    // 聚合人物类，通过聚合方式更加松耦合，利于扩展
    public Person person;
    public int id;
    public String title;

    public boolean work() {
        return true;
    }

}