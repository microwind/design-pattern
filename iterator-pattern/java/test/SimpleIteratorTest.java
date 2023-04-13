package test;

// 简单版Java迭代器实现，模拟List数据类型

interface SimpleIterator<T> {
  boolean hasNext();

  T next();
}

interface SimpleIterable<T> {
  SimpleIterator<T> iterator();
}

class SimpleList<T> implements SimpleIterable<T> {
  private T[] items;
  private int size;

  @SuppressWarnings("unchecked")
  public SimpleList(int capacity) {
    items = (T[]) new Object[capacity];
    size = 0;
  }

  public void add(T item) {
    items[size++] = item;
  }

  public T get(int index) {
    return items[index];
  }

  public int size() {
    return size;
  }

  @Override
  public SimpleIterator<T> iterator() {
    return new SimpleListIterator<>(this);
  }
}

class SimpleListIterator<T> implements SimpleIterator<T> {
  private SimpleList<T> list;
  private int index;

  public SimpleListIterator(SimpleList<T> list) {
    this.list = list;
    index = 0;
  }

  @Override
  public boolean hasNext() {
    return index < list.size();
  }

  @Override
  public T next() {
    T item = list.get(index);
    index++;
    return item;
  }
}

public class SimpleIteratorTest {
  public static void main(String[] args) {
    System.out.println("test start:");
    SimpleList<String> list = new SimpleList<>(3);
    list.add("Marry");
    list.add("Tom");
    list.add("Joey");

    SimpleIterator<String> iterator = list.iterator();
    while (iterator.hasNext()) {
      String item = iterator.next();
      System.out.println(item);
    }
  }
}

/**
 * 测试
 * jarry@jarrys-MacBook-Pro java % javac test/SimpleIteratorTest.java
 * jarry@jarrys-MacBook-Pro java % java test/SimpleIteratorTest
 * Marry
 * Tom
 * Joey
 */