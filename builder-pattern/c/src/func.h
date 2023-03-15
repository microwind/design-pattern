// 定义手机创建者结构体，用来创建Phone对象
typedef struct
{
  char name[50];
  int screen[2];
  int gpu_type;
} Phone;

// 定义手册创建者结构体，用来创建Manual对象
typedef struct
{
  char name[50];
  int screen[2];
  int gpu_type;
} Manual;

// 定义手册创建者结构体，用来创建Manual对象
typedef struct
{
  Phone *phone;
} PhoneBuilder;

// 定义手册创建者结构体，用来创建Manual对象
typedef struct
{
  Manual *manual;
} ManualBuilder;

/* application.c 应用调用文件 */
void make_iphone();
void make_huawei_phone();
void print_phone(Phone *phone);
void print_manual(Manual *manual);

/* director.c 指挥者文件 */
void build_iphone(PhoneBuilder *builder);
// 建造phone的huwei phone
void build_huawei_phone(PhoneBuilder *builder);
// 建造phone的mi phone
void build_mi_phone(PhoneBuilder *builder);
// 建造iphone手册
void build_iphone_manual(ManualBuilder *builder);
// 建造huwei manual手册
void build_huawei_manual(ManualBuilder *builder);
// 建造mi manual手册
void build_mi_manual(ManualBuilder *builder);

/* phone_builder.c 手机创建者文件 */
PhoneBuilder *create_phone_builder();
void reset_phone(PhoneBuilder *builder);
Phone *get_phone_product(PhoneBuilder *builder);
void free_phone_builder(PhoneBuilder *builder);
void set_phone_name(PhoneBuilder *p, char *name);
char *get_phone_name(PhoneBuilder *p);
void set_phone_screen(PhoneBuilder *p, int *screen);
int *get_phone_screen(PhoneBuilder *p);
void set_phone_gpu_type(PhoneBuilder *p, int gpu_type);
int get_phone_gpu_type(PhoneBuilder *p);

/* manual_builder.c 手机创建者文件 */
ManualBuilder *create_manual_builder();
void reset_manual(ManualBuilder *builder);
Manual *get_manual_product(ManualBuilder *builder);
void free_manual_builder(ManualBuilder *builder);
void set_manual_name(ManualBuilder *p, char *name);
char *get_manual_name(ManualBuilder *p);
void set_manual_screen(ManualBuilder *p, int *screen);
int *get_manual_screen(ManualBuilder *p);
void set_manual_gpu_type(ManualBuilder *p, int gpu_type);
int get_manual_gpu_type(ManualBuilder *p);
