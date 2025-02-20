/*
一个 面向过程编程 的 go 语言调用例子，展示了一个简单的学生成绩管理系统。
- 面向过程编程 的核心是通过函数分解问题，逻辑通过函数调用来组织，适合小型程序和简单任务。
- 函数式编程 强调纯函数和不可变数据，适合数据处理和并发编程。
- 面向对象编程 通过类和对象封装数据和行为，适合大型系统和模拟现实世界对象关系。
*/
package main

import (
    "fmt"
)

// 定义学生结构体
type Student struct {
    name  string
    score int
}

// 函数：打印学生信息
func printStudent(s Student) {
    fmt.Printf("Name: %s, Score: %d\n", s.name, s.score)
}

// 函数：计算平均成绩
func calculateAverage(students []Student) float64 {
    total := 0
    for _, student := range students {
        total += student.score
    }
    return float64(total) / float64(len(students))
}

// 函数：查找最高分学生
func findHighestScorer(students []Student) Student {
    highest := students[0]
    for _, student := range students[1:] {
        if student.score > highest.score {
            highest = student
        }
    }
    return highest
}

func main() {
    // 初始化学生数组
    students := []Student{
        {name: "Alice", score: 85},
        {name: "Bob", score: 90},
        {name: "Charlie", score: 78},
    }

    // 打印所有学生信息
    fmt.Println("Student List:")
    for _, student := range students {
        printStudent(student)
    }

    // 计算并打印平均成绩
    average := calculateAverage(students)
    fmt.Printf("Average Score: %.2f\n", average)

    // 查找并打印最高分学生
    highest := findHighestScorer(students)
    fmt.Print("Highest Scorer: ")
    printStudent(highest)
}

/*
jarry@Mac go % go run procedural.go
Student List:
Name: Alice, Score: 85
Name: Bob, Score: 90
Name: Charlie, Score: 78
Average Score: 84.33
Highest Scorer: Name: Bob, Score: 90
*/
