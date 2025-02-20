#include <stdio.h>
#include <string.h>

/*
一个 面向过程编程 的 C 语言调用例子，展示了一个简单的学生成绩管理系统。
- 面向过程编程 的核心是通过函数分解问题，逻辑通过函数调用来组织，适合小型程序和简单任务。
- 函数式编程 强调纯函数和不可变数据，适合数据处理和并发编程。
- 面向对象编程 通过类和对象封装数据和行为，适合大型系统和模拟现实世界对象关系。
*/
// 定义学生结构体
struct Student
{
    char name[50];
    int score;
};

// 函数：打印学生信息
void printStudent(struct Student s)
{
    printf("Name: %s, Score: %d\n", s.name, s.score);
}

// 函数：计算平均成绩
float calculateAverage(struct Student students[], int count)
{
    int total = 0;
    for (int i = 0; i < count; i++)
    {
        total += students[i].score;
    }
    return (float)total / count;
}

// 函数：查找最高分学生
struct Student findHighestScorer(struct Student students[], int count)
{
    struct Student highest = students[0];
    for (int i = 1; i < count; i++)
    {
        if (students[i].score > highest.score)
        {
            highest = students[i];
        }
    }
    return highest;
}

int main()
{
    // 初始化学生数组
    struct Student students[3];
    strcpy(students[0].name, "Alice");
    students[0].score = 85;
    strcpy(students[1].name, "Bob");
    students[1].score = 90;
    strcpy(students[2].name, "Charlie");
    students[2].score = 78;

    // 打印所有学生信息
    printf("Student List:\n");
    for (int i = 0; i < 3; i++)
    {
        printStudent(students[i]);
    }

    // 计算并打印平均成绩
    float average = calculateAverage(students, 3);
    printf("Average Score: %.2f\n", average);

    // 查找并打印最高分学生
    struct Student highest = findHighestScorer(students, 3);
    printf("Highest Scorer: ");
    printStudent(highest);

    return 0;
}

/*
jarry@Mac c % gcc procedural.c 
jarry@Mac c % ./a.out 
Student List:
Name: Alice, Score: 85
Name: Bob, Score: 90
Name: Charlie, Score: 78
Average Score: 84.33
Highest Scorer: Name: Bob, Score: 90
*/