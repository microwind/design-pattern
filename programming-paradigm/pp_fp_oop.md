# 面向过程、函数式编程、面向对象概述
## 面向过程编程
面向过程编程（Procedural Programming）是一种以过程为中心的编程范式。它把一个复杂的问题分解成一系列具体的步骤，每个步骤由一个或多个函数来实现。程序的执行流程按照这些函数的调用顺序依次进行。这种编程方式注重的是 “怎么做”，即实现问题的具体步骤和算法。

## 函数式编程
函数式编程（Functional Programming）是一种强调将计算视为函数求值的编程范式。它避免使用共享状态和可变数据，函数的输出仅依赖于输入，不产生任何副作用。函数式编程把函数作为一等公民，可以将函数作为参数传递给其他函数，也可以返回一个函数。
## 面向对象编程
面向对象编程（Object - Oriented Programming）是一种基于 “对象” 概念的编程范式。它将数据和操作数据的方法封装在对象中，通过对象之间的交互来实现程序的功能。面向对象编程具有三大特性：封装、继承和多态。

# 面向过程、函数式编程、面向对象区别
|编程范式|编程思路|数据和操作的关系|状态管理|函数/方法独立性|代码的可维护性和可扩展性|
| ---- | ---- | ---- | ---- | ---- | ---- |
|面向过程|以解决问题的步骤为核心，将大问题分解成多个小步骤，每个步骤对应一个函数，程序按函数调用顺序执行。如学生成绩管理系统，依次编写输入、计算、输出等函数并按顺序调用。|数据和操作分离，数据以全局或局部变量形式存在，操作通过独立函数实现，函数间通过参数传递数据交互。如图书管理系统中，图书信息存全局数组，添加、查找等操作由不同函数完成并操作数组。|通常使用全局变量或静态变量管理程序状态，变量可在不同函数中被访问和修改，状态共享直接但易导致混乱。如游戏程序用全局变量记录玩家得分和生命值，修改可能致异常。|函数通常依赖全局状态或其他函数执行结果，独立性较弱，一个函数修改可能影响其他函数。如图形绘制程序，修改位置函数可能影响颜色函数效果。|简单程序代码结构清晰，易理解维护。但随程序规模增大，函数调用关系复杂，全局变量增加耦合度，添加新功能可能需修改多个函数，维护和扩展变差。如简单文件处理程序添加加密功能可能需改多个函数。|
|函数式编程|强调将计算视为函数求值，避免使用共享状态和可变数据，把函数作为一等公民，通过函数组合和高阶函数构建复杂程序，更关注“做什么”。如用高阶函数处理数据过滤、映射等操作。|数据通常是不可变的，函数接收输入数据并返回新的数据，不修改原始数据。函数间通过返回值传递数据，形成数据的流动。如使用 map、filter 等函数对列表进行操作。|避免使用共享状态和可变数据，函数输出仅取决于输入，不产生副作用。函数执行不依赖外部状态，每次相同输入得到相同输出。如计算阶乘的纯函数，不依赖外部变量。|函数更加独立，可复用性强，一个函数不依赖其他函数的状态或执行结果，可独立完成特定功能。可方便地在不同场景中复用。如通用的排序函数可用于不同类型列表排序。|由于函数的独立性和无副作用特性，代码易于理解和测试。添加新功能时可通过组合现有函数实现，扩展方便。如在数据处理流程中添加新的数据转换步骤，只需添加新函数并组合。|
|面向对象编程|基于“对象”概念，将数据和操作封装在对象中，通过对象间交互实现程序功能，具有封装、继承和多态特性。如设计一个动物类，不同动物子类继承并实现不同行为。|数据和操作封装在对象中，对象的方法用于操作对象的属性，外部通过对象接口与对象交互。如汽车对象有启动、加速等方法操作其速度等属性。|对象有自己的内部状态，通过对象的方法来管理和修改状态，状态的修改由对象自身控制，外部不能直接访问和修改。如银行账户对象通过存款、取款方法管理余额。|对象的方法相对独立，每个对象负责自己的功能和状态管理，对象间通过消息传递进行交互。如不同类型的图形对象有自己的绘制方法，相互独立。|通过封装隐藏内部实现细节，通过继承实现代码复用，通过多态增强代码灵活性。在处理大型复杂系统时，易于扩展和维护。如添加新的动物类型，只需创建新的子类并实现必要方法。|

# 代码对比
## c语言面向过程
```c
// 面向过程编程：C语言示
// 通过函数操作全局或静态数据，强调步骤和流程。逻辑通过函数调用来组织。
// 数据和函数分离，书籍数据存储在全局数组中，函数直接操作这些数据。
#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 3

typedef struct {
    char title[50];
    int isBorrowed;
} Book;

Book books[MAX_BOOKS] = {{"The Great Gatsby", 0}, {"1984", 0}, {"Brave New World", 0}};
int bookCount = 3;

void borrowBook(const char* title) {
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].title, title) == 0 && books[i].isBorrowed == 0) {
            books[i].isBorrowed = 1;
            printf("'%s' has been borrowed.\n", title);
            return;
        }
    }
    printf("Could not borrow '%s'.\n", title);
}

void returnBook(const char* title) {
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].title, title) == 0 && books[i].isBorrowed == 1) {
            books[i].isBorrowed = 0;
            printf("'%s' has been returned.\n", title);
            return;
        }
    }
    printf("Could not return '%s'.\n", title);
}

void displayBooks() {
    for (int i = 0; i < bookCount; i++) {
        printf("Title: %s, Status: %s\n", books[i].title, books[i].isBorrowed ? "Borrowed" : "Available");
    }
}

int main() {
    borrowBook("1984");
    returnBook("1984");
    displayBooks();
    return 0;
}
```

## js函数式编程
```js
// JS函数式编程：
// 避免状态改变，使用不可变数据结构和纯函数，强调计算结果而非过程。每次操作返回新的数据。
// 通过高阶函数（如 map）处理数据，强调数据的不可变性。
const books = [
    { title: "The Great Gatsby", isBorrowed: false },
    { title: "1984", isBorrowed: false },
    { title: "Brave New World", isBorrowed: false }
];

function borrowBook(books, title) {
    return books.map(book => 
        book.title === title && !book.isBorrowed ? { ...book, isBorrowed: true } : book
    );
}

function returnBook(books, title) {
    return books.map(book => 
        book.title === title && book.isBorrowed ? { ...book, isBorrowed: false } : book
    );
}

function displayBooks(books) {
    books.forEach(book => {
        console.log(`Title: ${book.title}, Status: ${book.isBorrowed ? 'Borrowed' : 'Available'}`);
    });
}

let updatedBooks = borrowBook(books, "1984");
updatedBooks = returnBook(updatedBooks, "1984");

displayBooks(updatedBooks);
```

## js面向对象
```js
// JS通过定义类来实现面向对象编程
// 使用类和对象封装数据和行为，每个书籍都是一个具有属性和方法的对象。
// 通过方法操作对象内部状态，逻辑通过对象之间的交互来组织。
class Book {
    constructor(title, author) {
        this.title = title;
        this.author = author;
        this.isBorrowed = false;
    }

    borrow() {
        if (!this.isBorrowed) {
            this.isBorrowed = true;
            console.log(`'${this.title}' has been borrowed.`);
        } else {
            console.log(`'${this.title}' is already borrowed.`);
        }
    }

    returnBook() {
        if (this.isBorrowed) {
            this.isBorrowed = false;
            console.log(`'${this.title}' has been returned.`);
        } else {
            console.log(`'${this.title}' is not borrowed.`);
        }
    }

    displayInfo() {
        console.log(`Title: ${this.title}, Author: ${this.author}, Status: ${this.isBorrowed ? 'Borrowed' : 'Available'}`);
    }
}

class Library {
    constructor() {
        this.books = [];
    }

    addBook(book) {
        this.books.push(book);
    }

    findBook(title) {
        return this.books.find(book => book.title === title);
    }

    displayBooks() {
        this.books.forEach(book => book.displayInfo());
    }
}

// 使用示例
const library = new Library();
library.addBook(new Book("The Great Gatsby", "F. Scott Fitzgerald"));
library.addBook(new Book("1984", "George Orwell"));

let book = library.findBook("The Great Gatsby");
if (book) {
    book.borrow();
    book.returnBook();
}

library.displayBooks();
```

## python函数式
```py
"""
在Python中，利用高阶函数、不可变数据结构和纯函数来实现函数式编程。
在这个例子中，使用了dataclass和frozen=True来创建不可变的书籍对象，
并通过返回新的书籍列表而不是修改原有的列表来处理借阅和归还操作。
这种方法有助于减少副作用，使代码更易于理解和测试。
"""
from dataclasses import dataclass
from typing import List, Tuple

@dataclass(frozen=True)
class Book:
    title: str
    author: str
    is_borrowed: bool

def borrow_book(books: List[Book], title: str) -> Tuple[List[Book], str]:
    for i, book in enumerate(books):
        if book.title == title and not book.is_borrowed:
            updated_books = books[:i] + [Book(book.title, book.author, True)] + books[i+1:]
            return updated_books, f"'{title}' has been borrowed."
    return books, f"Could not borrow '{title}'."

def return_book(books: List[Book], title: str) -> Tuple[List[Book], str]:
    for i, book in enumerate(books):
        if book.title == title and book.is_borrowed:
            updated_books = books[:i] + [Book(book.title, book.author, False)] + books[i+1:]
            return updated_books, f"'{title}' has been returned."
    return books, f"Could not return '{title}'."

def display_books(books: List[Book]):
    for book in books:
        status = "Borrowed" if book.is_borrowed else "Available"
        print(f"Title: {book.title}, Author: {book.author}, Status: {status}")

# 使用示例
books = [
    Book("The Great Gatsby", "F. Scott Fitzgerald", False),
    Book("1984", "George Orwell", False)
]

books, message = borrow_book(books, "The Great Gatsby")
print(message)

books, message = return_book(books, "The Great Gatsby")
print(message)

display_books(books)
```

## python面向对象
```py
# 面向对象编程：在Python示例中
# 每个书籍都被表示为一个Book对象，具有自己的属性和方法。
# 通过方法操作对象内部状态，逻辑通过对象之间的交互来组织。
class Book:
    def __init__(self, title, author):
        self.title = title
        self.author = author
        self.borrowed = False

    def borrow(self):
        if not self.borrowed:
            self.borrowed = True
            print(f"Book '{self.title}' has been borrowed.")
        else:
            print(f"Book '{self.title}' is already borrowed.")

    def return_book(self):
        if self.borrowed:
            self.borrowed = False
            print(f"Book '{self.title}' has been returned.")
        else:
            print(f"Book '{self.title}' is not borrowed.")

    def display_info(self):
        status = "Borrowed" if self.borrowed else "Available"
        print(f"Title: {self.title}, Author: {self.author}, Status: {status}")

class Library:
    def __init__(self):
        self.books = []

    def add_book(self, book):
        self.books.append(book)

    def find_book(self, title):
        for book in self.books:
            if book.title == title:
                return book
        return None

    def display_books(self):
        for book in self.books:
            book.display_info()

if __name__ == "__main__":
    library = Library()
    library.add_book(Book("The Great Gatsby", "F. Scott Fitzgerald"))
    library.add_book(Book("1984", "George Orwell"))

    book = library.find_book("The Great Gatsby")
    if book:
        book.borrow()
        book.return_book()

    library.display_books()
```

## java面向对象
```java
// Java示例面向对象编程：
// 通过类和对象封装数据和行为，每个书籍是一个 Book 对象。
// 通过方法操作对象内部状态，逻辑通过对象之间的交互来组织。
// 这种方法使得代码更加模块化、易于维护，并且可以通过继承等机制增强扩展性。
import java.util.ArrayList;
import java.util.List;

class Book {
    private String title;
    private String author;
    private boolean borrowed;

    public Book(String title, String author) {
        this.title = title;
        this.author = author;
        this.borrowed = false;
    }

    public void borrow() {
        if (!borrowed) {
            borrowed = true;
            System.out.println("Book '" + title + "' has been borrowed.");
        } else {
            System.out.println("Book '" + title + "' is already borrowed.");
        }
    }

    public void returnBook() {
        if (borrowed) {
            borrowed = false;
            System.out.println("Book '" + title + "' has been returned.");
        } else {
            System.out.println("Book '" + title + "' is not borrowed.");
        }
    }

    public void displayInfo() {
        String status = borrowed ? "Borrowed" : "Available";
        System.out.println("Title: " + title + ", Author: " + author + ", Status: " + status);
    }

    public String getTitle() {
        return title;
    }
}

class Library {
    private List<Book> books = new ArrayList<>();

    public void addBook(Book book) {
        books.add(book);
    }

    public Book findBook(String title) {
        for (Book book : books) {
            if (book.getTitle().equals(title)) {
                return book;
            }
        }
        return null;
    }

    public void displayBooks() {
        for (Book book : books) {
            book.displayInfo();
        }
    }

    public static void main(String[] args) {
        Library library = new Library();
        library.addBook(new Book("The Great Gatsby", "F. Scott Fitzgerald"));
        library.addBook(new Book("1984", "George Orwell"));

        Book book = library.findBook("The Great Gatsby");
        if (book != null) {
            book.borrow();
            book.returnBook();
        }

        library.displayBooks();
    }
}
```

# 分析
- 面向过程编程：如上述C代码所示，面向过程编程主要围绕着过程或函数来组织代码。它通过定义一系列操作数据的过程来解决问题。
- 函数式编程：在函数式编程中，如JavaScript示例所示，强调不可变数据结构和纯函数的应用，尽量避免副作用，使得代码更加清晰和易于测试。
- 面向对象编程：如Python和Java示例所示，面向对象编程则侧重于类和对象的概念，将数据和操作封装在一起，通过继承、多态等机制提高代码的复用性和扩展性。