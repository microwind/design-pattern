#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 定义部件接口或抽象类，分支和叶子节点遵循该类约定
typedef struct OrganizationComponent
{
    char name[200];
    void (*add)(struct OrganizationComponent *, struct OrganizationComponent *);
    void (*remove)(struct OrganizationComponent *, struct OrganizationComponent *);
    struct OrganizationComponent *(*get_child)(struct OrganizationComponent *, int);
    void (*operation)(struct OrganizationComponent *);
    int children_size;
    struct OrganizationComponent **children;
    // 如果是柔型数组，则自动扩展数组长度，但可能导致出现乱码现象，故采取固定长度数组
    // struct OrganizationComponent *children[];
} OrganizationComponent;
void add_component(OrganizationComponent *, OrganizationComponent *);
void remove_component(OrganizationComponent *, OrganizationComponent *);
OrganizationComponent *get_child_component(OrganizationComponent *, int);
void print_children(OrganizationComponent *children[], int children_size);

// 实现部件的树枝构件1
typedef struct CompanyComposite
{
    char name[200];
    void (*add)(struct OrganizationComponent *, struct OrganizationComponent *);
    void (*remove)(struct OrganizationComponent *, struct OrganizationComponent *);
    struct OrganizationComponent *(*get_child)(struct OrganizationComponent *, int);
    void (*operation)(struct CompanyComposite *);
    int children_size;
    struct OrganizationComponent **children;
} CompanyComposite;
CompanyComposite *company_composite_constructor(char *name);

// 实现部件的树枝构件2
typedef struct DepartmentComposite
{
    char name[200];
    void (*add)(struct OrganizationComponent *, struct OrganizationComponent *);
    void (*remove)(struct OrganizationComponent *, struct OrganizationComponent *);
    struct OrganizationComponent *(*get_child)(struct OrganizationComponent *, int);
    void (*operation)(struct DepartmentComposite *);
    int children_size;
    struct OrganizationComponent **children;
} DepartmentComposite;
DepartmentComposite *department_composite_constructor(char *name);

// 实现部件的叶子节点，叶子节点不能再含有子节点
typedef struct EmployeeLeaf
{
    char name[200];
    void (*add)(struct OrganizationComponent *, struct OrganizationComponent *);
    void (*remove)(struct OrganizationComponent *, struct OrganizationComponent *);
    struct OrganizationComponent *(*get_child)(struct OrganizationComponent *, int);
    void (*operation)(struct EmployeeLeaf *);
    int children_size;
    struct OrganizationComponent **children;
} EmployeeLeaf;
EmployeeLeaf *employee_leaf_constructor(char *name);
