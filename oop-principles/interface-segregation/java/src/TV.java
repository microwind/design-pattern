package src;

/**
 * TV实现类，实现TV控制接口的全部方法
 */
public class TV implements TVController {
  @Override
  public void turnOn() {
    System.out.println("Turn on TV");
    // 执行电视打开操作
  }

  @Override
  public void turnOff() {
    System.out.println("Turn off TV");
    // 执行电视关闭操作
  }

  @Override
  public void adjustTVVolume(int volume) {
    // 执行调节音量操作
    System.out.println("Adjust TV volume to " + volume);
  }

  @Override
  public void changeTVChannel(int channel) {
    // 执行频道切换操作
    System.out.println("Change TV channel to " + channel);
  }

}