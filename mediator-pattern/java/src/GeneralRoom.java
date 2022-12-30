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
   public void sendTo(String from, String to, String message) {
      System.out.println(">>GeneralRoom:sendTo() [from: " + from + " message: " + message + " to: " + to + " ]");
      for (AbstractUser user : users) {
         // 定向发送
         if (user.getName().equals(to)) {
            user.recieve(from, message);
         }
      }
   }

   // 作为中介者通知给全体用户
   @Override
   public void send(String from, String message) {
      System.out.println(">>GeneralRoom:send() [from: " + from + " message: " + message + "]");
      for (AbstractUser user : users) {
         user.recieve(from, message);
      }
   }
}
