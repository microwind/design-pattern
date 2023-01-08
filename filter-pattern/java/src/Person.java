package src;

// 定义一个实体类，用来过滤的对象
public class Person {

   private String name;
   private String gender;
   private String status;

   public Person(String name, String gender, String status) {
      this.name = name;
      this.gender = gender;
      this.status = status;
   }

   public String getName() {
      return name;
   }

   public String getGender() {
      return gender;
   }

   public String getStatus() {
      return status;
   }
}