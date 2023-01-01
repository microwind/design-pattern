package src;

// 具体享元角色，实现抽象接口，用于执行实际操作
public class ConcreteFlyweight implements Flyweight {
   private String name;
   private String type = "piano";

   public ConcreteFlyweight(String name) {
      this.name = name;
   }

   // 这里state属于外部状态，在调用时外部传入。
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