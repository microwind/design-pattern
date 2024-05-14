package src;

/**
 * 工程师类继承雇员类
 */
public class Engineer extends Employee {

  public Engineer(int id, String title, Person person) {
    this.id = id;
    this.title = title;
    this.person = person;
  }

  @Override
  public boolean work() {
    System.out.println("Engineer is working." + " id = " + this.id
        + ", title = " + this.title + " name = " + person.getName() + ", age = " + person.getAge());
    return true;
  }
}