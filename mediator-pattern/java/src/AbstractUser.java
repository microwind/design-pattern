package src;

// 定义抽象形状类，关联图形操作接口
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

   public abstract void sendTo(String to, String message);

   public abstract void recieve(String from, String message);

   public String getName() {
      return this.name;
   }
}