package src;

// 手册类
public class Manual {
  private String name = "PhoneManualName";
  private Integer[] screen = { 0, 0 };
  private Integer gpuType = 0;
  private Integer pages = 0;

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

  public void setPages(Integer pages) {
    this.pages = pages;
  }

  public Integer getPages() {
    return this.pages;
  }

  public String toString() {
    return "[name=" + name + ", screen=" + screen.toString() + ", gpuType=" + gpuType + "]";
  }

}