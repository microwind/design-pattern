package src;

// 建造者接口
public interface Builder {
  public void reset();
  public void setName(String name);
  public void setScreen(Integer[] screen);
  public void setGPU(Integer no); 
}
