  // src/mvc/Model.java
  // 模型层。负责基础数据处理，经控制层转发，由Service层调用，最后映射到View层。
  // 注意Model、DTO、POJO、Entity、VO的区别：
  // Model: 数据模型，用于在View层展示数据的对象。Model将各层传递的数据封装成实体类，以便传输和展示。
  // Entity: 数据表对应到实体类的映射，也就是DAO层表与类的字段映射，是一个未被持久化的对象。
  // POJO: 简单Java Bean，除了属性和get、set方法外不包含具体的业务逻辑方法，纯模型对象。
  // DTO: 数据传输对象，前端向后台提交数据时，通过DTO来实现了View与Model之间的解耦，View层不再直接引用Model，而是引用DTO对象。
  // VO: Value Object视图模型，后台向前端传递数据时的模型，适用于展示层，它的作用是把某个指定页面或API的所有数据全部封装起来。
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
      // 其他方法
  }
