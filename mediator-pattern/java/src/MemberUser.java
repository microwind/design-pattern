package src;

// 会员用户继承了抽象用户，实现了具体功能
public class MemberUser extends AbstractUser {
   public MemberUser(String name) {
      super(name);
   }

   @Override
   public void send(String message) {
      System.out.println("MemberUser:send() [user: " + this.getName() + " message:" + message + "]");
      // 通过中介者来中转消息
      this.roomMediator.send(this, message);
   }

   @Override
   public void sendTo(AbstractUser to, String message) {
      System.out
            .println("MemberUser:sendTo() [user: " + this.getName() + " message:" + message + " to: " + to.getName() + "]");
      // 通过中介者来中转消息
      this.roomMediator.sendTo(this, to, message);
   }

   @Override
   public void recieve(AbstractUser from, String message) {
      System.out.println("MemberUser:recieve() [user: " + this.getName() + " message: " + message
            + " from user:" + from.getName() + "]");
   }
}