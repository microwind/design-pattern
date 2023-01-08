package src;

// 访问者Visitor抽象接口，定义不同的visit方法
public interface Visitor {
  public void visit(ConcreteElementA concreteElementA);

  public void visit(ConcreteElementB concreteElementB);

  public String getName();
}
