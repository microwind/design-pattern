package src;

// 代理类也实现了基础接口
public class ProxyImage implements Image {

  private RealImage realImage;
  private String fileName;

  public ProxyImage(String fileName) {
    this.fileName = fileName;
  }

  @Override
  public void display() {
    System.out.println("ProxyImage::display() " + fileName);
    if (realImage == null) {
      realImage = new RealImage(fileName);
    }
    // 代理类调用真实类的方法
    realImage.display();
  }
}