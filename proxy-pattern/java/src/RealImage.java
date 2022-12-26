package src;

// 真实类实现基础接口
public class RealImage implements Image {

  private String fileName;

  public RealImage(String fileName) {
    // 在初始化时执行内部逻辑
    this.fileName = fileName;
    loadFromDisk(fileName);
  }

  @Override
  public void display() {
    System.out.println("RealImage::display() " + fileName);
  }

  // 这个方法只是内部使用
  private void loadFromDisk(String fileName) {
    System.out.println("RealImage::loadFromDisk()  " + fileName);
  }
}
