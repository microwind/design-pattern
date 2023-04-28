package src;

// 手机建造者实现了建造者接口
public class PhoneBuilder implements Builder {
  private Phone phone;

  public void reset() {
    this.phone = new Phone();
  }

  public Builder setName(String name) {
    this.phone.setName(name);
    return this;
  }

  public Builder setScreen(Integer[] screen) {
    this.phone.setScreen(screen);
    return this;
  }

  public Builder setGPU(Integer no) {
    this.phone.setGpuType(no);
    return this;
  }

  public Phone getProduct() {
    return this.phone;
  }
}
