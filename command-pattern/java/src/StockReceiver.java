package src;

// 命令模式真正的执行类，不直接对外，通过command来调用
public class StockReceiver {

   private String name;
   private int num;

   public StockReceiver(String name, int num) {
      this.name = name;
      this.num = num;
   }

   public void buy() {
      System.out.println(this.getClass().getName() + "::buy() [name=" + this.name + " num=" + this.num + "]");
   }

   public void sell() {
      System.out.println(this.getClass().getName() + "::sell() [name=" + this.name + " num=" + this.num + "]");
   }

   public void setName(String name) {
      this.setName(name);
   }

   public String getName() {
      return this.name;
   }

   public void setNum(int num) {
      this.num = num;
   }

   public int getNum() {
      return this.num;
   }
}
