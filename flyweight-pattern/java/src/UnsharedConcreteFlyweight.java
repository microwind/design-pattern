package src;

// 无需共享的角色，每次都是新实例
public class UnsharedConcreteFlyweight implements Flyweight {
   private String name;
   private String type = "guitar";

   public UnsharedConcreteFlyweight(String name) {
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