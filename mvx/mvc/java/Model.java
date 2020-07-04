  // src/mvc/Model.java
  public class Model {
      private String name;
      private Integer num;
      public Model() {
      }
      public Model(String name, Integer num) {
          this.name = name;
          this.num = num;
      }
      public String getName() {
          return this.name;
      }
      public Integer getNum() {
          return this.num;
      }
  }