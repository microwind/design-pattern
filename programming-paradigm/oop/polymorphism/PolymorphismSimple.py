class A:
    def show(self, obj):
        if isinstance(obj, D):
            return "A and D"
        else:
            return "A and A"


class B(A):
    def show(self, obj):
        if isinstance(obj, B):
            return "B and B"
        elif isinstance(obj, A):
            return "B and A"
        else:
            return super().show(obj)


class C(B):
    pass


class D(B):
    pass


def main():
    a = A()
    ab = B()
    b = B()
    c = C()
    d = D()

    print("1--" + a.show(b))   # 输出：A and A
    print("2--" + a.show(c))   # 输出：A and A
    print("3--" + a.show(d))   # 输出：A and D
    print("4--" + ab.show(b))  # 输出：B and B
    print("5--" + ab.show(c))  # 输出：B and B
    print("6--" + ab.show(d))  # 输出：B and B
    print("7--" + b.show(b))   # 输出：B and B
    print("8--" + b.show(c))   # 输出：B and B
    print("9--" + b.show(d))   # 输出：B and B
    print("10--" + ab.show(a))  # 输出：B and A


if __name__ == "__main__":
    main()
