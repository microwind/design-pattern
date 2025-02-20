/*
多态：即同一个行为具有多个不同表现形式或形态的能力。
表现形式为，子类重写父类方法，实现类实现接口方法，子类重写抽象类方法等。
多态三个必要条件：继承、重写、父类引用指向子类对象。多态有效消除类型之间的耦合，并提供灵活的可扩展方案。
本例子简单清晰明了的Java多态，能看懂这个例子就懂了什么是多态。
*/

// 父类A
class A {
    public String show(D object) {
        return ("A and D");
    }

    public String show(A object) {
        return ("A and A");
    }

    // 默认注释掉。可开关注释测试下
    // public String show(B object) {
    // return ("A and B");
    // }
}

// 子类B
class B extends A {
    public String show(B object) {
        return ("B and B");
    }

    public String show(A object) {
        return ("B and A");
    }
}

// 孙子类C
class C extends B {
}

// 孙子类D
class D extends B {
}

// 测试验证
public class PolymorphismSimple {
    public static void main(String[] args) {
        // 父类声明自己
        A a = new A();
        // 父类声明子类
        A ab = new B();
        // 子类声明自己
        B b = new B();
        C c = new C();
        D d = new D();

        // 1) A and A。b的类型是B，也是B的实例，A里没有show(B)方法，但有show(A)方法。B的父类是A，因此定位到A.show(A)。
        System.out.println("1) " + a.show(b));

        // 2) A and A。c的类型是C，也是C的实例，C继承B，B继承A。A里没有show(C)方法，也没有show(B)方法，最后指向A.show(A)。
        System.out.println("2) " + a.show(c));

        // 3) A and D, d的类型是D，也是D的实例，D继承B，B继承A。A里有show(D)方法，直接定位到A.show(D)。
        System.out.println("3) " + a.show(d));

        // 4) B and A, ab是B的实例，但用A声明，即向上转型得到的类型是A，运行时才能确定具体该调用哪个方法。
        // ab是B的实例对象，但引用类型是A。类型是在编译时确定，因此从类型开始定位方法。
        // A类中没有show(B)方法，但有show(A)方法，因为A是B的父类，ab也是A的实例，于是定位到A.show(A)方法。
        // 由于B是A的子类，且B重写了A的show(A)，A的方法被覆盖了，于是定位到B.show(A)，这就是动态绑定。
        // 虽然B中有show(B)方法，但是因为ab的类型是A，编译时根据类型定位到A的方法，而不是B。

        // 以下几种可开关打开/注释代码测试下。
        // -
        // 若A里有show(A)和show(B)，B里有show(B)有show(A)，则编译时关联到A.show(B)，因B覆盖了A.show(B)，动态绑定到B.show(B)。
        // -
        // 若A里有show(A)和show(B)，B里无show(B)有show(A)，则编译时关联到A.show(B)，因B无覆盖，则直接调用A.show(B)。
        // -
        // 若A里有show(A)无show(B)，B里无show(B)有show(A)，则编译时关联到A.show(A)，因B覆盖了A.show(A)，动态绑定到B.show(A)。
        // -
        // 若A里有show(A)无show(B)，B里无show(A)有show(B)，则编译时关联到A.show(A)，因B无覆盖，则直接调用A.show(A)。
        // 查找顺序为：编译时根据引用类型确定所属类 -> 根据重载参数类型定位（类型按子->父->祖逐级往上查找）到类的具体方法（包括继承的方法） ->
        // 运行时实例对象覆盖（覆盖只有子->父一层）了引用类型的同名方法 -> 定位到实例对象的方法。
        System.out.println("4) " + ab.show(b));

        // 5) B and A。ab是B的实例，类型是A。从A类没找到show(C)方法，也没找到A.show(B)方法，找到A.show(A)方法。A.show(A)被B.show(A)覆盖，因此调用B.show(A)。
        System.out.println("5) " + ab.show(c));

        // 6) A and D。A里面有show(D)的方法，直接定位到。
        System.out.println("6) " + ab.show(d));

        // 7) B and B。B里面有show(B)的方法，直接定位到。
        System.out.println("7) " + b.show(b));

        // 8) B and B。B没有show(c)方法，但有show(B)方法。C继承自B，父类型是B，因此调用B.show(B)。
        System.out.println("8) " + b.show(c));

        // 9) A and D。B中没有show(D)方法，B继承A，A里有show(D), 故调用A.show(D)方法。
        System.out.println("9) " + b.show(d));

        // 10) B and A。父类声明子类，存在向上转型。A里有show(A)，被B.show(A)覆盖了，因此定位到B.show(A)。
        System.out.println("10) " + ab.show(a));

    }
}

/**
 * 测试
 * jarry@jarrys-MacBook-Pro polymorphism % javac PolymorphismSimple.java
 * jarry@jarrys-MacBook-Pro polymorphism % java PolymorphismSimple
 * 1) A and A
 * 2) A and A
 * 3) A and D
 * 4) B and A
 * 5) B and A
 * 6) A and D
 * 7) B and B
 * 8) B and B
 * 9) A and D
 * 10) B and A
 */