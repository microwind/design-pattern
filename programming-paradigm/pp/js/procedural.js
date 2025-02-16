/*
一个 面向过程编程 的 JavaScript 示例，展示了一个简单的学生成绩管理系统。
- 面向过程编程 的核心是通过函数分解问题，逻辑通过函数调用来组织，适合小型程序和简单任务。
- 函数式编程 强调纯函数和不可变数据，适合数据处理和并发编程。
- 面向对象编程 通过类和对象封装数据和行为，适合大型系统和模拟现实世界对象关系。
*/

// 定义学生结构体
function Student(name, score) {
    this.name = name;
    this.score = score;
}

// 函数：打印学生信息
function printStudent(student) {
    console.log(`Name: ${student.name}, Score: ${student.score}`);
}

// 函数：计算平均成绩
function calculateAverage(students) {
    let total = 0;
    for (let i = 0; i < students.length; i++) {
        total += students[i].score;
    }
    return total / students.length;
}

// 函数：查找最高分学生
function findHighestScorer(students) {
    let highest = students[0];
    for (let i = 1; i < students.length; i++) {
        if (students[i].score > highest.score) {
            highest = students[i];
        }
    }
    return highest;
}

// 初始化学生数组
let students = [
    new Student("Alice", 85),
    new Student("Bob", 90),
    new Student("Charlie", 78)
];

// 打印所有学生信息
console.log("Student List:");
students.forEach(student => printStudent(student));

// 计算并打印平均成绩
let average = calculateAverage(students);
console.log(`Average Score: ${average.toFixed(2)}`);

// 查找并打印最高分学生
let highest = findHighestScorer(students);
console.log("Highest Scorer:");
printStudent(highest);

/*
jarry@Mac js % node procedural.js 
Student List:
Name: Alice, Score: 85
Name: Bob, Score: 90
Name: Charlie, Score: 78
Average Score: 84.33
Highest Scorer:
Name: Bob, Score: 90
*/