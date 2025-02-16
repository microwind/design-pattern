/*
一个 面向过程编程 的 Java 语言调用例子，展示了一个简单的学生成绩管理系统。
- 面向过程编程 的核心是通过函数分解问题，逻辑通过函数调用来组织，适合小型程序和简单任务。
- 函数式编程 强调纯函数和不可变数据，适合数据处理和并发编程。
- 面向对象编程 通过类和对象封装数据和行为，适合大型系统和模拟现实世界对象关系。
*/
public class Procedural {
    // 定义学生类
    static class Student {
        String name;
        int score;

        public Student(String name, int score) {
            this.name = name;
            this.score = score;
        }
    }

    // 函数：打印学生信息
    public static void printStudent(Student s) {
        System.out.printf("Name: %s, Score: %d\n", s.name, s.score);
    }

    // 函数：计算平均成绩
    public static float calculateAverage(Student[] students) {
        int total = 0;
        for (Student student : students) {
            total += student.score;
        }
        return (float) total / students.length;
    }

    // 函数：查找最高分学生
    public static Student findHighestScorer(Student[] students) {
        Student highest = students[0];
        for (int i = 1; i < students.length; i++) {
            if (students[i].score > highest.score) {
                highest = students[i];
            }
        }
        return highest;
    }

    public static void main(String[] args) {
        // 初始化学生数组
        Student[] students = {
                new Student("Alice", 85),
                new Student("Bob", 90),
                new Student("Charlie", 78)
        };

        // 打印所有学生信息
        System.out.println("Student List:");
        for (Student student : students) {
            printStudent(student);
        }

        // 计算并打印平均成绩
        float average = calculateAverage(students);
        System.out.printf("Average Score: %.2f\n", average);

        // 查找并打印最高分学生
        Student highest = findHighestScorer(students);
        System.out.print("Highest Scorer: ");
        printStudent(highest);
    }
}

/*
 * jarry@Mac java % java Procedural.java
 * Student List:
 * Name: Alice, Score: 85
 * Name: Bob, Score: 90
 * Name: Charlie, Score: 78
 * Average Score: 84.33
 * Highest Scorer: Name: Bob, Score: 90
 */