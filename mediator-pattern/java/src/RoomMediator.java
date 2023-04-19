package src;

// 定义中介者接口或抽象类
public interface RoomMediator {
   public void register(AbstractUser user);
   public void sendTo(AbstractUser from, AbstractUser to, String message);
   public void send(AbstractUser from, String message);
}