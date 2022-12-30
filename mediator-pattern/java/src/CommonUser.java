package src;

// 普通用户继承了抽象用户，实现了具体功能
public class CommonUser extends AbstractUser {

   public CommonUser(String name) {
      super(name);
   }

   @Override
   public void send(String message) {
      System.out.println("CommonUser:send() [user: " + this.getName() + " send message:" + message + "]");
      // 通过中介者来中转消息
      this.roomMediator.send(this.getName(), message);
   }

   @Override
   public void sendTo(String to, String message) {
      System.out.println("CommonUser:sendTo() [user: " + this.getName() + " send message:" + message + " to: " + to + "]");
      // 通过中介者来中转消息
      this.roomMediator.sendTo(this.getName(), to, message);
   }

   @Override
   public void recieve(String from, String message) {
      System.out.println("CommonUser:recieve() [user: " + this.getName() + " recieve message: " + message + " from user:" + from + "]");
   }

}