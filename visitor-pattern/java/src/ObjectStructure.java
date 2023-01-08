package src;

import java.util.*;

// 结构对象(ObjectStructure)
public class ObjectStructure {

  // 可以想象为一台电脑，聚合了各种设备元素
  private String name = "Computer Structure";
  private List<Element> elements = new ArrayList<Element>();

  // 结构对象初始化聚合了其他元素
  public ObjectStructure() {
    addElement(new ConcreteElementA());
    addElement(new ConcreteElementB());
  }

  public void addElement(Element element) {
    elements.add(element);
  }

  // 传入访问者分发给其他元素
  public void accept(Visitor visitor) {
    System.out
        .println("ObjectStructure::accept() [visitor.class = " + visitor.getClass().getSimpleName() + " visitor.name = "
            + visitor.getName() + "]");
    for (Element element : elements) {
      element.accept(visitor);
    }
  }

  public String getName() {
    return this.name;
  }

}
