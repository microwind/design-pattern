/*
一个 面向过程编程 的 rust 语言调用例子，展示了一个简单的学生成绩管理系统。
- 面向过程编程 的核心是通过函数分解问题，逻辑通过函数调用来组织，适合小型程序和简单任务。
- 函数式编程 强调纯函数和不可变数据，适合数据处理和并发编程。
- 面向对象编程 通过类和对象封装数据和行为，适合大型系统和模拟现实世界对象关系。
*/
// 定义学生结构体
struct Student {
    name: String,
    score: i32,
}

// 函数：打印学生信息
fn print_student(s: &Student) {
    println!("Name: {}, Score: {}", s.name, s.score);
}

// 函数：计算平均成绩
fn calculate_average(students: &[Student]) -> f64 {
    let total: i32 = students.iter().map(|s| s.score).sum();
    total as f64 / students.len() as f64
}

// 函数：查找最高分学生
fn find_highest_scorer(students: &[Student]) -> &Student {
    let mut highest = &students[0];
    for student in students.iter().skip(1) {
        if student.score > highest.score {
            highest = student;
        }
    }
    highest
}

fn main() {
    // 初始化学生数组
    let students = [
        Student {
            name: String::from("Alice"),
            score: 85,
        },
        Student {
            name: String::from("Bob"),
            score: 90,
        },
        Student {
            name: String::from("Charlie"),
            score: 78,
        },
    ];

    // 打印所有学生信息
    println!("Student List:");
    for student in &students {
        print_student(student);
    }

    // 计算并打印平均成绩
    let average = calculate_average(&students);
    println!("Average Score: {:.2}", average);

    // 查找并打印最高分学生
    let highest = find_highest_scorer(&students);
    print!("Highest Scorer: ");
    print_student(highest);
}

/*
jarry@Mac rust % rustc procedural.rs -o procedural.out
jarry@Mac rust % ./procedural.out 
Student List:
Name: Alice, Score: 85
Name: Bob, Score: 90
Name: Charlie, Score: 78
Average Score: 84.33
Highest Scorer: Name: Bob, Score: 90
*/