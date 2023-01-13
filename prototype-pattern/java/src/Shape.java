package src;

// 基础抽象类
public abstract class Shape implements Cloneable {

  private int width;
  private int height;
  private String color = "";
  protected String type;

  public Shape() {

  }

  public String getType() {
    return type;
  }

  // 抽象方法，子类覆盖
  public abstract void draw();

  public void setWidth(int width) {
    this.width = width;
  }

  public int getWidth() {
    return this.width;
  }

  public int getHeight() {
    return this.height;
  }

  public void setHeight(int height) {
    this.height = height;
  }

  public void setColor(String color) {
    this.color = color;
  }

  public String getColor() {
    return this.color;
  }

  // 克隆方法
  public Object clone() {
    Object clone = null;
    try {
      clone = super.clone();
    } catch (CloneNotSupportedException e) {
      e.printStackTrace();
    }
    return clone;
  }

  @Override
  public String toString() {
    return String.format("{width = %s, height = %s, type = %s, color = %s }",
        this.width, this.height, this.type, this.color);
  }
}
