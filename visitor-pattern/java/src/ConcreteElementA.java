package src;

// 具体的元素实现者A
public class ConcreteElementA extends Element {
  // 可以设想为显示器
  private String name = "Monitor Element";

  @Override
  public void accept(Visitor visitor) {
    System.out
        .println(
            "ConcreteElementA::accept() [visitor.class = " + visitor.getClass().getSimpleName() + " visitor.name = "
                + visitor.getName() + "]");
    visitor.visit(this);
  }

  public void operate() {
    System.out.println("ConcreteElementA::operate() [" + this.getName() + "]");
  }

  public String getName() {
    return this.name;
  }
}