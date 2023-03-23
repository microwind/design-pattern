// 定义手机创建者结构体，用来创建Phone对象
typedef struct Phone
{
  char name[50];
  int screen[2];
  int gpu_type;
} Phone;

// 定义手册创建者结构体，用来创建Manual对象
typedef struct Manual
{
  char name[50];
  int screen[2];
  int gpu_type;
} Manual;

// 基础建造者，用于构建复杂对象的接口
typedef struct Builder
{
  struct Phone *phone;
  struct Manual *manual;
  void (*reset)(struct Builder *);
  void (*set_name)(struct Builder *, char *);
  char *(*get_name)(struct Builder *);
  void (*set_screen)(struct Builder *, int *);
  void (*set_gpu_type)(struct Builder *, int);
  struct Phone *(*get_phone_product)(struct Builder *);
  struct Manual *(*get_manual_product)(struct Builder *);
} Builder;

// 定义手机创建者结构体，聚合了Manual对象
typedef struct PhoneBuilder
{
  struct Phone *phone;
  // get_product可以统一放在Builder
  struct Phone *(*get_product)(struct PhoneBuilder *);
} PhoneBuilder;

// 定义手册创建者结构体，聚合了Phone对象
typedef struct ManualBuilder
{
  struct Manual *manual;
  struct Manual *(*get_product)(struct ManualBuilder *);
} ManualBuilder;


// 定义指挥者，指挥Builder来创建对象，可以根据需要创建不同产品
typedef struct Director
{
  void (*build_iphone)(struct Builder *builder);
  void (*build_huawei_phone)(struct Builder *builder);
  void (*build_mi_phone)(struct Builder *builder);
} Director;

/* director.c 指挥者文件 */
Director *create_director();

/* phone_builder.c 手机创建者文件 */
PhoneBuilder *create_phone_builder();

/* manual_builder.c 手册创建者文件 */
ManualBuilder *create_manual_builder();

/* application.c 应用调用文件 */
void make_iphone();
void make_huawei_phone();
void print_phone(Phone *phone);
void print_manual(Manual *manual);