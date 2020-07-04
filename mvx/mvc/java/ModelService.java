  // src/mvc/ModelService.java
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
  }