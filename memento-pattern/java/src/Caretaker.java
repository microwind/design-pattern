package src;

import java.util.*;

// 负责人(Caretaker)角色，只负责保存备忘录记录，不能修改备忘录对象的内容
public class Caretaker {
    // 备忘录可以是一个记录，也可以就是一个对象，根据业务场景设置
    private List<Memento> mementoList = new ArrayList<Memento>();

    public void add(Memento memento) {
        System.out.println(this.getClass().getName() + "::add() [memento = " + memento.getClass().getName() + "]");
        mementoList.add(memento);
    }

    public Memento get(int index) {
        return mementoList.get(index);
    }

    public List<Memento> getMementoList() {
        return this.mementoList;
    }
}