package src;

// 定义中介者接口或抽象类
public interface RoomMediator {
   public void register(AbstractUser user);
   public void sendTo(String from, String to, String message);
   public void send(String from, String message);
}