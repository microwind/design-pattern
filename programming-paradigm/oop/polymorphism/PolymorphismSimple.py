class A:
    def show(self, obj):
        if isinstance(obj, D):
            return "A and D"
        elif isinstance(obj, A):
            return "A and A"
        else:
            return "Unknown"

class B(A):
    def show(self, obj):
        if isinstance(obj, B) and not isinstance(obj, D):
            return "B and B"
        elif isinstance(obj, A):
            return "B and A"
        else:
            return super().show(obj)

class C(B):
    pass

class D(B):
    pass

if __name__ == "__main__":
    a = A()
    ab = B()
    b = B()
    c = C()
    d = D()

    print("1)", a.show(b))   # 期望: A and A
    print("2)", a.show(c))   # 期望: A and A
    print("3)", a.show(d))   # 期望: A and D
    print("4)", ab.show(b))  # 期望: B and B
    print("5)", ab.show(c))  # 期望: B and A
    print("6)", ab.show(d))  # 期望: A and D
    print("7)", b.show(b))   # 期望: B and B
    print("8)", b.show(c))   # 期望: B and B
    print("9)", b.show(d))   # 期望: A and D
    print("10)", ab.show(a)) # 期望: B and A
