package src;

import java.util.*;

// 中介者的具体实现类
public class GeneralRoom implements RoomMediator {
   public List<AbstractUser> users = new ArrayList<AbstractUser>();

   @Override
   public void register(AbstractUser user) {
      // 用户注册登记，追加用户列表
      user.setRoomMediator(this);
      users.add(user);
   }

   // 作为中介者通知给某个用户
   @Override
   public void sendTo(AbstractUser from, AbstractUser to, String message) {
      System.out.println(
            "GeneralRoom:sendTo() [from: " + from.getName() + " message: " + message + " to: " + to.getName() + " ]");
      // 根据用户名称定向发送
      to.recieve(from, message);
   }

   // 作为中介者通知给全体用户
   @Override
   public void send(AbstractUser from, String message) {
      System.out.println("GeneralRoom:send() [from: " + from.getName() + " message: " + message + "]");
      for (AbstractUser user : users) {
         user.recieve(from, message);
      }
   }
}
