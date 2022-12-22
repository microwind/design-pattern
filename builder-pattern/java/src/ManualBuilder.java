package src;

// 使用手册建造者类也实现了建造者接口
public class ManualBuilder implements Builder {
  private Manual manual;

  public void reset() {
    this.manual = new Manual();
  }

  public void setName(String name) {
    this.manual.setName(name);
  }

  public void setScreen(Integer[] screen) {
    this.manual.setScreen(screen);
  }

  public void setGPU(Integer no) {
    this.manual.setGpuType(no);
  }

  public Manual getProduct() {
    return this.manual;
  }
}
