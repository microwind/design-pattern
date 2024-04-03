package src;

/**
 * TV控制接口，包括TV需要的控制方法，供TV具体对象实现
 * 每个具体控制对象有其自身的接口，不跟其他对象混在一起
 */
public interface TVController extends DeviceController {
  public void adjustTVVolume(int volume);

  public void changeTVChannel(int channel);
}