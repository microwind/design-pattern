package src;

// 对象迭代器，实现了抽象迭代器的方法，聚合了对象列表
public class ObjectIterator implements Iterator {

   private ObjectList objectList;

   int index;

   public ObjectIterator(ObjectList objectList) {
      this.objectList = objectList;
   }

   @Override
   public boolean hasNext() {
      if (index < objectList.size()) {
         return true;
      }
      return false;
   }

   @Override
   public Object next() {
      if (this.hasNext()) {
         // 返回数据对象提供的get方法，每访问一次则增加下标
         return objectList.get(index++);
      }
      return null;
   }
}