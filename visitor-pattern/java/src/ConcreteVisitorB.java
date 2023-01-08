package src;

// 具体访问者B
public class ConcreteVisitorB implements Visitor {

  // 假如由不同厂商是程序的访问者
  private String name = "Apple Visitor";

  @Override
  public void visit(ConcreteElementA concreteElementA) {
    System.out.println(
        "ConcreteVisitorB::visit() [Element.class = " + concreteElementA.getClass().getSimpleName()
            + " Element.name = "
            + concreteElementA.getName() + "]");
    concreteElementA.operate();
  }

  @Override
  public void visit(ConcreteElementB concreteElementB) {
    System.out.println(
        "ConcreteVisitorB::visit() [Element.class = " + concreteElementB.getClass().getSimpleName()
            + " Element.name = "
            + concreteElementB.getName() + "]");
    concreteElementB.operate();
  }

  public String getName() {
    return this.name;

  }
}