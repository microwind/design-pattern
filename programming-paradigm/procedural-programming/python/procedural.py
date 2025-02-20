"""
一个 面向过程编程 的 C 语言调用例子，展示了一个简单的学生成绩管理系统。
- 面向过程编程 的核心是通过函数分解问题，逻辑通过函数调用来组织，适合小型程序和简单任务。
- 函数式编程 强调纯函数和不可变数据，适合数据处理和并发编程。
- 面向对象编程 通过类和对象封装数据和行为，适合大型系统和模拟现实世界对象关系。
"""
# 定义学生类（这里使用字典模拟结构体）
# 打印学生信息


def print_student(s):
    print(f"Name: {s['name']}, Score: {s['score']}")

# 计算平均成绩


def calculate_average(students):
    total = sum(student['score'] for student in students)
    return total / len(students)

# 查找最高分学生


def find_highest_scorer(students):
    highest = students[0]
    for student in students[1:]:
        if student['score'] > highest['score']:
            highest = student
    return highest


if __name__ == "__main__":
    # 初始化学生数组
    students = [
        {"name": "Alice", "score": 85},
        {"name": "Bob", "score": 90},
        {"name": "Charlie", "score": 78}
    ]

    # 打印所有学生信息
    print("Student List:")
    for student in students:
        print_student(student)

    # 计算并打印平均成绩
    average = calculate_average(students)
    print(f"Average Score: {average:.2f}")

    # 查找并打印最高分学生
    highest = find_highest_scorer(students)
    print("Highest Scorer: ", end="")
    print_student(highest)

"""
jarry@Mac python % python procedural.py 
Student List:
Name: Alice, Score: 85
Name: Bob, Score: 90
Name: Charlie, Score: 78
Average Score: 84.33
Highest Scorer: Name: Bob, Score: 90
"""
