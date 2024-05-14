package src;

/**
 * 组合/聚合复用用组合来替代继承，该类聚合到雇员类
 * 组合，相对紧密，表示为组成部件与物体的关系
 * 聚合，相对松散，表示为个体与整体/模块的关系
 */
public class Person {
    public String name;
    public int age;
    public int gender;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }
}