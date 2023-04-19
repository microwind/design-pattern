package src;

// 定义抽象用户类，聚合中介者
public abstract class AbstractUser {

   private String name;
   public RoomMediator roomMediator;

   public AbstractUser(String name) {
      this.name = name;
   }

   public void setRoomMediator(RoomMediator roomMediator) {
      this.roomMediator = roomMediator;
   }

   public abstract void send(String message);

   public abstract void sendTo(AbstractUser to, String message);

   public abstract void recieve(AbstractUser from, String message);

   public String getName() {
      return this.name;
   }
}