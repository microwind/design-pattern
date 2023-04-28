package src;

// 使用手册建造者类也实现了建造者接口
public class ManualBuilder implements Builder {
  private Manual manual;

  public void reset() {
    this.manual = new Manual();
  }

  public Builder setName(String name) {
    this.manual.setName(name);
    return this;
  }

  public Builder setScreen(Integer[] screen) {
    this.manual.setScreen(screen);
    return this;
  }

  public Builder setGPU(Integer no) {
    this.manual.setGpuType(no);
    return this;
  }

  public Manual getProduct() {
    return this.manual;
  }
}
