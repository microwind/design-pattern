package src;

// 发起人(Originator)负责生成状态快照，即利用一个新备忘录对象将自己的内部状态存储起来
public class Originator {

    private String state;

    // 每次创建一个新备忘录来保存状态
    public Memento saveMemento() {
        System.out.println(this.getClass().getName() + "::saveMemento() [state = " + state + "]");
        return new Memento(state);
    }

    // 从备忘录中恢复状态
    public void restoreMemento(Memento memento) {
        this.state = memento.getState();
    }

    public String getState() {
        return state;
    }

    public void setState(String state) {
        this.state = state;
    }
}