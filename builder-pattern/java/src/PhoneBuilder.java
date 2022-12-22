package src;

// 手机建造者实现了建造者接口
public class PhoneBuilder implements Builder {
  private Phone phone;

  public void reset() {
    this.phone = new Phone();
  }

  public void setName(String name) {
    this.phone.setName(name);
  }

  public void setScreen(Integer[] screen) {
    this.phone.setScreen(screen);
  }

  public void setGPU(Integer no) {
    this.phone.setGpuType(no);
  }

  public Phone getProduct() {
    return this.phone;
  }
}
