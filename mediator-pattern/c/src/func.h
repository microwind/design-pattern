#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct RoomMediator RoomMediator;
typedef struct AbstractUser AbstractUser;
typedef struct CommonUser CommonUser;
typedef struct MemberUser MemberUser;
typedef struct GeneralRoom GeneralRoom;

// 定义中介者接口或抽象类
typedef struct RoomMediator
{
    void (*registry)(RoomMediator *, AbstractUser *);
    void (*send)(AbstractUser *sender, char *message);
    void (*send_to)(AbstractUser *sender, AbstractUser *receiver, char *message);
    int users_length;
    struct AbstractUser **users;
} RoomMediator;

// 中介者的具体实现类，实现抽象中介者接口，聚合了全体用户，提供中转消息服务
typedef struct GeneralRoom
{
    void (*registry)(GeneralRoom *, AbstractUser *);
    void (*send)(AbstractUser *sender, char *message);
    void (*send_to)(AbstractUser *sender, AbstractUser *receiver, char *message);
    int users_length;
    struct AbstractUser **users;
} GeneralRoom;
GeneralRoom *general_room_constructor();

// 基础用户类，供具体继承
typedef struct AbstractUser
{
    char name[50];
    struct RoomMediator *mediator;
    void (*set_mediator)(AbstractUser *, RoomMediator *);
    void (*send)(AbstractUser *, char *message);
    void (*send_to)(AbstractUser *sender, AbstractUser *receiver, char *message);
    void (*recieve)(AbstractUser *receiver, AbstractUser *sender, char *message);
} AbstractUser;

// 实现基础类的普通用户1，聚合了中介者
typedef struct CommonUser
{
    char name[50];
    struct RoomMediator *mediator;
    void (*set_mediator)(CommonUser *, RoomMediator *);
    void (*send)(CommonUser *, char *message);
    void (*send_to)(CommonUser *sender, AbstractUser *receiver, char *message);
    void (*recieve)(CommonUser *receiver, AbstractUser *sender, char *message);
} CommonUser;
CommonUser *common_user_constructor(char *name);

// 实现基础类的普通用户2，聚合了中介者
typedef struct MemberUser
{
    char name[50];
    struct RoomMediator *mediator;
    void (*set_mediator)(MemberUser *, RoomMediator *);
    void (*send)(MemberUser *, char *message);
    void (*send_to)(MemberUser *sender, AbstractUser *receiver, char *message);
    void (*recieve)(MemberUser *receiver, AbstractUser *sender, char *message);
} MemberUser;
MemberUser *member_user_constructor(char *name);
