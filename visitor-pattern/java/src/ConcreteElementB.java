package src;

// 具体的元素实现者B
public class ConcreteElementB extends Element {
  private String name = "Keyboard Element";

  @Override
  public void accept(Visitor visitor) {
    System.out.println(
        "ConcreteElementB::accept() [visitor.class = " + visitor.getClass().getSimpleName() + " visitor.name = "
            + visitor.getName() + "]");
    visitor.visit(this);
  }

  public void operate() {
    System.out.println("ConcreteElementB::operate() [" + this.getName() + "]");
  }

  public String getName() {
    return this.name;
  }
}
