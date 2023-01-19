package src;

// 产品类
public class Phone {
  private String name = "PhoneName";
  private Integer[] screen = { 0, 0 };
  private Integer gpuType = 0;

  public void setName(String name) {
    this.name = name;
  }

  public String getName() {
    return this.name;
  }

  public void setScreen(Integer[] screen) {
    this.screen = screen;
  }

  public Integer[] getScreen() {
    return this.screen;
  }

  public void setGpuType(Integer type) {
    this.gpuType = type;
  }

  public Integer getGpuType() {
    return this.gpuType;
  }

  public String toString() {
    return "[name=" + name + ", screen=" + screen.toString() + ", gpuType=" + gpuType + "]";
  }

}
