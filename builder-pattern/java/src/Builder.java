package src;

// 建造者接口
public interface Builder {
  public void reset();
  public Builder setName(String name);
  public Builder setScreen(Integer[] screen);
  public Builder setGPU(Integer no); 
}
