package src;

// 对象列表，是一种数据容器，可以创建一个迭代器
public class ObjectList implements Container {
   private Object[] objects = { "Google", "Apple", "Amazon" };

   @Override
   public Iterator createIterator() {
      System.out.println(this.getClass().getName() + "::createIterator() [获取迭代器 ObjectIterator]");
      // 把当前对象传给迭代器
      return new ObjectIterator(this);
   }

   public void setObjects(Object[] objects) {
      this.objects = objects;
   }

   public int size() {
      return objects.length;
   }

   public Object get(int index) {
      return objects[index];
   }
}