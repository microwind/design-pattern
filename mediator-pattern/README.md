# 【中介者设计模式详解】C/Java/JS/Go/Python/TS不同语言实现

# 简介
中介者模式（Mediator Pattern）是一种行为型模式。它限制对象之间的直接交互，它用一个中介对象来封装一系列的动作，以让对象之间进行交流。中介者使各个对象不需要显式地相互引用，从而使其耦合松散，而且可以独立地改变它们之间的交互。

当一些对象和其他对象紧密耦合以致难以对其进行修改时，或当组件因过于依赖其他组件而无法在不同应用中复用时，可使用中介者模式。

# 作用
1. 用来降低多个对象和类之间的通信复杂性。
2. 对象之间不再显式地相互引用，但可以独立地改变它们之间的交互，从而保持松耦合。

# 实现步骤
1. 定义一个工具接口，供不同工具类来实现。建立多个具体工具类实现基础工具接口。
2. 定义一个基础抽象类，里面聚合了工具接口，相当于桥接。
3. 再重新定义一个新抽象类，继承自基础抽象类，并补充一些方法。
4. 建立具体对象类继承新抽象类，调用桥接接口里的方法来实现功能。

# UML
<img src="../docs/uml/mediator-pattern.png">

# Java代码

## 中介者抽象接口
```java
// RoomMediator.java 定义中介者接口或抽象类
public interface RoomMediator {
   public void register(AbstractUser user);
   public void sendTo(AbstractUser from, AbstractUser to, String message);
   public void send(AbstractUser from, String message);
}
```

## 通用中介者
```java
// GeneralRoom.java 中介者的具体实现类
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
```

## 抽象用户类
```java
// AbstractUser.java 定义抽象用户类，聚合中介者
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
```

## 具体用户对象
```java
// CommonUser.java 普通用户继承了抽象用户，实现了具体功能
public class CommonUser extends AbstractUser {

   public CommonUser(String name) {
      super(name);
   }

   @Override
   public void send(String message) {
      System.out.println("CommonUser:send() [user: " + this.getName() + " message:" + message + "]");
      // 通过中介者来中转消息
      this.roomMediator.send(this, message);
   }

   @Override
   public void sendTo(AbstractUser to, String message) {
      System.out.println("CommonUser:sendTo() [user: " + this.getName() + " message:" + message + " to: " + to.getName() + "]");
      // 通过中介者来中转消息
      this.roomMediator.sendTo(this, to, message);
   }

   @Override
   public void recieve(AbstractUser from, String message) {
      System.out.println("CommonUser:recieve() [user: " + this.getName() + " message: " + message + " from:" + from.getName() + "]");
   }
}
```

```java
// MemberUser.java 会员用户继承了抽象用户，实现了具体功能
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
```

## 测试调用
```java
public class Test {

  public static void start() {
  /**
   * 中介者模式用一个中介对象来封装一系列动作，让对象之间利用中介者来交流。
   * 这里聊天室就是一个中介者，用户和用户之间的消息传递，全部依靠聊天室来完成。
   * 先给聊天室注册用户，也给用户绑定上中介者，双方彼此持有关系。
   * 中介者的成员之间的消息传递通过中介者来代理传达。
   */

    // 声明一个聊天室
    GeneralRoom generalRoom = new GeneralRoom();
    // 给聊天室添加点不同的人
    AbstractUser user1 = new CommonUser("user1");
    generalRoom.register(user1);
    CommonUser user2 = new CommonUser("user2");
    generalRoom.register(user2);
    MemberUser user3 = new MemberUser("user3");
    generalRoom.register(user3);

    // user1 发送给全体
    user1.send("hi, I'm " + user1.getName() + ".");
    // user2 发送给 user3
    user2.sendTo(user3, "haha.");

  }

  public static void main(String[] args) {
    System.out.println("test start:");
    start();
  }

}
```

# Go代码

## 中介者抽象接口
```go
// RoomMediator.go 定义中介者接口或抽象类
type RoomMediator interface {
  Register(user AbstractUser)
  SendTo(from AbstractUser, to AbstractUser, message string)
  Send(from AbstractUser, message string)
}
```

## 通用中介者
```go
// GeneralRoom.go 中介者的具体实现类
type GeneralRoom struct {
  users []AbstractUser
}

func (g *GeneralRoom) Register(user AbstractUser) {
  // 用户注册登记，追加用户列表
  user.SetRoomMediator(g)
  g.users = append(g.users, user)
}

// 作为中介者通知给某个用户
func (g *GeneralRoom) SendTo(from AbstractUser, to AbstractUser, message string) {
  fmt.Println("GeneralRoom::SendTo() [from: " + from.GetName() + " message: " + message + " to: " + to.GetName() + "]")
  // 定向发送给某个用户，名称唯一
  to.Recieve(from, message)
}

// 作为中介者通知给全体用户
func (g *GeneralRoom) Send(from AbstractUser, message string) {
  fmt.Println("GeneralRoom::Send() [from: " + from.GetName() + " message: " + message + "] ")
  for _, user := range g.users {
    user.Recieve(from, message)
  }
}
```

## 抽象用户类
```go
// AbstractUser.go 定义抽象用户类，聚合中介者
type AbstractUser interface {
  SetRoomMediator(roomMediator RoomMediator)
  Send(message string)
  SendTo(to AbstractUser, message string)
  Recieve(from AbstractUser, message string)
  GetName() string
}
```

## 具体用户对象
```go
// CommonUser.go 普通用户继承了抽象用户，实现了具体功能
type CommonUser struct {
  Name         string
  roomMediator RoomMediator
}

func (c *CommonUser) SetRoomMediator(roomMediator RoomMediator) {
  c.roomMediator = roomMediator
}

func (c *CommonUser) Send(message string) {
  fmt.Println("CommonUser:Send() [user: " + c.GetName() + " message: " + message + "]")
  // 通过中介者来中转消息
  c.roomMediator.Send(c, message)
}

func (c *CommonUser) SendTo(to AbstractUser, message string) {
  fmt.Println("CommonUser:SendTo() [user: " + c.GetName() + " message: " + message + "]")
  // 通过中介者来中转消息
  c.roomMediator.SendTo(c, to, message)
}

func (c *CommonUser) Recieve(from AbstractUser, message string) {
  fmt.Println("CommonUser:Recieve() [user: " + c.GetName() + " message: " + message + " from: " + from.GetName() + "]")
}

func (c *CommonUser) SetName(name string) {
  c.Name = name
}

func (c *CommonUser) GetName() string {
  return c.Name
}
```

```go
// MemberUser.go 会员用户继承了抽象用户，实现了具体功能
type MemberUser struct {
  // Name首字母大写以便跨模块访问
  Name         string
  roomMediator RoomMediator
}

func (c *MemberUser) SetRoomMediator(roomMediator RoomMediator) {
  c.roomMediator = roomMediator
}

func (c *MemberUser) Send(message string) {
  fmt.Println("MemberUser:Send() [user: " + c.GetName() + " message: " + message + "]")
  // 通过中介者来中转消息
  c.roomMediator.Send(c, message)
}

func (c *MemberUser) SendTo(to AbstractUser, message string) {
  fmt.Println("MemberUser:SendTo() [user: " + c.GetName() + " message: " + message + "]")
  // 通过中介者来中转消息
  c.roomMediator.SendTo(c, to, message)
}

func (c *MemberUser) Recieve(from AbstractUser, message string) {
  fmt.Println("MemberUser:Recieve() [user: " + c.GetName() + " message: " + message + " from: " + from.GetName() + "]")
}

func (c *MemberUser) SetName(name string) {
  c.Name = name
}

func (c *MemberUser) GetName() string {
  return c.Name
}
```

## 测试调用
```go
func main() {
  fmt.Println("test start:")
  /**
   * 中介者模式用一个中介对象来封装一系列动作，让对象之间利用中介者来交流。
   * 这里聊天室就是一个中介者，用户和用户之间的消息传递，全部依靠聊天室来完成。
   * 先给聊天室注册用户，也给用户绑定上中介者，双方彼此持有关系。
   * 中介者的成员之间的消息传递通过中介者来代理传达。
   */
  // 声明一个聊天室
  var generalRoom = new(src.GeneralRoom)
  // 给聊天室添加点不同的人
  var user1 = &src.CommonUser{
    Name: "user1",
  }
  generalRoom.Register(user1)

  var user2 = &src.CommonUser{
    Name: "user2",
  }
  generalRoom.Register(user2)

  var user3 = &src.MemberUser{
    Name: "user3",
  }
  generalRoom.Register(user3)

  // user1 发送给全体
  user1.Send("hi, I'm " + user1.GetName() + ".")
  // user2 发送给 user3
  user2.SendTo(user3, "haha.")
}

```

# C语言简版
```c
#include <stdio.h>

/**
 * 中介者模式是一种行为型设计模式，它可以用来减少类之间的直接依赖关系，
 * 将对象之间的通信封装到一个中介者对象中，从而使得各个对象之间的关系更加松散。
 * 在中介者模式中，对象之间不再直接相互交互，而是通过中介者来中转消息。
 */

typedef struct Colleague Colleague;
typedef struct Mediator Mediator;

// 定义抽象交互对象类
struct Colleague
{
  int id;
  struct Mediator *mediator;
  void (*send)(struct Colleague *sender, char *message);
  void (*send_to)(struct Colleague *sender, Colleague *receiver, char *message);
  void (*receive)(struct Colleague *receiver, Colleague *sender, char *message);
};

// 定义中介者类
struct Mediator
{
  struct Colleague **colleagues;
  int colleagues_length;
  void (*send)(Colleague *sender, char *message);
  void (*send_to)(Colleague *sender, Colleague *receiver, char *message);
};

// 交互对象发送消息
void colleague_send(Colleague *sender, char *message)
{
  printf("\r\n colleague_send() [sender->id=%d message=%s]", sender->id, message);
  Mediator *mediator = sender->mediator;
  // 由中介者代为转发消息给全体接收者
  mediator->send(sender, message);
}

// 交互对象发送消息
void colleague_send_to(Colleague *sender, Colleague *receiver, char *message)
{
  printf("\r\n colleague_send_to() [sender->id=%d receiver->id=%d message=%s]", sender->id, receiver->id, message);
  Mediator *mediator = sender->mediator;
  // 由中介者代为转发消息给指定接收者
  mediator->send_to(sender, receiver, message);
}

// 对象接收消息
void colleague_receive(Colleague *receiver, Colleague *sender, char *message)
{
  printf("\r\n colleague_receive() [receiver->id=%d send->id=%d message=%s]", receiver->id, sender->id, message);
}

// 中介者发送消息
void mediator_send(Colleague *sender, char *message)
{
  printf("\r\n mediator_send() [sender->id=%d message=%s]", sender->id, message);
  Colleague *receiver;
  for (int i = 0; i < sender->mediator->colleagues_length; i++)
  {
    // 中介者通知全体接收者
    receiver = sender->mediator->colleagues[i];
    receiver->receive(receiver, sender, message);
  }
}

// 中介者发送消息
void mediator_send_to(Colleague *sender, Colleague *receiver, char *message)
{
  // 中介者通知指定接收者
  printf("\r\n mediator_send_to() [sender->id=%d receiver->id=%d message=%s]", sender->id, receiver->id, message);
  receiver->receive(receiver, sender, message);
}

// 初始化交互对象类
void colleague_constructor(Colleague *self, int id)
{
  self->id = id;
  self->send = colleague_send;
  self->send_to = colleague_send_to;
  self->receive = colleague_receive;
}

// 初始化中介者类
void mediator_constructor(Mediator *self, Colleague **colleagues, int colleagues_length)
{
  self->colleagues = colleagues;
  self->colleagues_length = colleagues_length;
  // 给每个对象绑定中介者
  for (int i = 0; i < self->colleagues_length; i++)
  {
    self->colleagues[i]->mediator = self;
  }
  self->send = &mediator_send;
  self->send_to = &mediator_send_to;
}

// test

int main()
{
  // 初始化具体交互对象a，分别绑定相关函数
  Colleague colleague_a;
  colleague_constructor(&colleague_a, 1);

  // 初始化具体交互对象b，分别绑定相关函数
  Colleague colleague_b;
  colleague_constructor(&colleague_b, 2);

  // 定义交互对象数组
  Colleague *colleagues[] = {&colleague_a, &colleague_b};
  int colleagues_length = sizeof(colleagues) / sizeof(colleagues[0]);

  printf("colleagues_length=%d", colleagues_length);

  // 初始化中介者类，绑定交互对象
  Mediator mediator;
  mediator_constructor(&mediator, colleagues, colleagues_length);

  // 交互类发送消息
  colleague_a.send(&colleague_a, "Hi, all! I'm a.");
  printf("\r\n ==== \r\n");
  colleague_a.send_to(&colleague_a, &colleague_b, "Hello, colleague_b. I am a!");
  printf("\r\n ==== \r\n");
  colleague_b.send_to(&colleague_b, &colleague_a, "Hi, colleague_a! I'm b.");
  return 0;
}

```

## 更多语言版本
不同语言实现设计模式：[https://github.com/microwind/design-pattern](https://github.com/microwind/design-pattern)