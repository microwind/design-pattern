package src;

/**
 * 管理者类继承雇员类
 */
public class Manager extends Employee {

    public Manager(int id, String title, Person person) {
        this.id = id;
        this.title = title;
        this.person = person;
    }

    @Override
    public boolean work() {
        System.out.println("Manager is working." + " id = " + this.id
                + ", title = " + this.title + " name = " + person.getName() + ", age = " + person.getAge());
        return true;
    }
}