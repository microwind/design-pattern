package src;

// 网络模块
public class NetworkModule {

   public void request() {
      System.out.println(this.getClass().getName() + "::request() 远程读取。");
   }
}
