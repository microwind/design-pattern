package src;

// 抽象元素(Element)，定义accept方法，传入抽象访问者
abstract class Element {
  public abstract void accept(Visitor visitor);
}