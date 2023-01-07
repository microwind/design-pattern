package src;

// 备忘录(Memento)角色，负责存储发起人传入的状态
public class Memento {
   private String state;

   public Memento(String state) {
      System.out.println(this.getClass().getName() + "::Memento() [state = " + state + "]");
      this.state = state;
   }

   public String getState() {
      return state;
   }

   public void setState(String state) {
      this.state = state;
   }
}
