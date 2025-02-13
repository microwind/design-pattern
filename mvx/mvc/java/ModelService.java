  // src/mvc/ModelService.java
  // 1. Service层，也叫ModelService，承接Controller访问，调用Model层，主要负责业务逻辑处理和数据处理。
  // 2. 在MVC架构中，可以没有Service层，只要有Controller、Model和View即可。
  // 3. 业务逻辑和数据模型往往比较复杂，为了解耦，将Controller里的逻辑处理，Model里面的数据处理抽取出来组成Sevice层。
  // 4. 在Model和Service基础上，还衍生DTO、POJO、Entity、VO等概念，这都是为了解耦，使得程序更容易理解和扩展。
  import java.util.Optional;
  public class ModelService {
      Model model;
      public Optional<Model> getModel() {
          if (this.model == null) {
              this.model = new Model("Thomas", 10);
          }
          // do something
          return Optional.of(this.model);
      }
      // 其他方法
  }
