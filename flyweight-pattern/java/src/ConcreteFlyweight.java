package src;

// 具体享元角色，实现抽象接口，用于共享状态，一个类被创建以后就不用重复创建了
public class ConcreteFlyweight implements Flyweight {
   private String name;
   private String type;

   public ConcreteFlyweight(String name) {
      // 内部状态，即不会随着环境的改变而改变的可共享部分
      // 这里的name也是对象保存的key
      this.name = name;
      this.type = "piano";
      System.out.println("ConcreteFlyweight::ConcreteFlyweight(name) [创建具体享元" + name + "]");
   }

  // 这里state属于外部状态，由外部调用时传入
  // 也可以把非共享的对象传入进来
   @Override
   public void operate(String state) {
      System.out.println(
            String.format("%s::operate() [%s %s %s]", this.getClass().getName(), this.getName(),
                  this.getType(), state));
   }

   public String getName() {
      return this.name;
   }

   public String getType() {
      return this.type;
   }
}