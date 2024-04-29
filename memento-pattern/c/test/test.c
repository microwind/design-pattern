#include "../src/func.h"

int main(void)
{
  printf("test start:\r\n");
  /*
   * 备忘录模式是在不暴露对象实现细节的情况下保存和恢复对象之前的状态。
   * 先声明发起人Originator，再声明负责人Caretaker，发起人生成备忘录Memento
   * 通过负责人则保存备忘录历史记录，读取备忘录由负责人来完成。
   */
  Originator *originator = originator_constructor();
  Caretaker *caretaker = caretaker_constructor();
  // 发起人产生一个状态
  originator->set_state(originator, "state1");
  // 覆盖了状态，那么前面的状态未保存
  originator->set_state(originator, "state2");
  // 发起人生成备忘录，一般添加时直接保存即可
  Memento *memento = originator->save_memento(originator);
  // 负责人保添加备忘录历史记录
  caretaker->add(caretaker, memento);

  // 直接生成备忘录并添加到负责人的备忘录列表
  originator->set_state(originator, "state3");
  caretaker->add(caretaker, originator->save_memento(originator));
  originator->set_state(originator, "state4");
  caretaker->add(caretaker, originator->save_memento(originator));

  printf("\r\n 发起人当前的状态: %s", originator->get_state(originator));

  // 发起人通过负责人那里取出状态
  originator->restore_memento(originator, caretaker->get(caretaker, 0));
  printf("\r\n 第一个保存的状态: %s", originator->get_state(originator));
  originator->restore_memento(originator, caretaker->get(caretaker, 1));
  printf("\r\n 第二个保存的状态: %s", originator->get_state(originator));

  printf("\r\n 遍历全部备忘录:");
  for (int i = 0; i < caretaker->memento_length; i++)
  {
    // 外部一般不直接访问备忘录里面的状态，而是逐个恢复备忘录，再取出状态来
    originator->restore_memento(originator, caretaker->get(caretaker, i));
    printf("\r\n %d) state=%s", i, originator->get_state(originator));
  }
}

// jarry@jarrys-MacBook-Pro c % gcc test/test.c ./src/*.c
// jarry@jarrys-MacBook-Pro c % ./a.out
/**
test start:

 originator_constructor() [构建通用聊天室]
 caretaker_constructor() [构建Caretaker]
 Originator::save_memento() [state = state2]
 memento_constructor() [构建Memento name=Memento state=state2]
 Caretaker::add() [memento = Memento]
 Originator::save_memento() [state = state3]
 memento_constructor() [构建Memento name=Memento state=state3]
 Caretaker::add() [memento = Memento]
 Originator::save_memento() [state = state4]
 memento_constructor() [构建Memento name=Memento state=state4]
 Caretaker::add() [memento = Memento]
 发起人当前的状态: state4
 第一个保存的状态: state2
 第二个保存的状态: state3
 遍历全部备忘录:
 0) state=state2
 1) state=state3
 2) state=state4%
 */