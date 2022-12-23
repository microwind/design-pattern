package src;

// VideoPlayer支持多种视频格式播放，相对复杂，定义通用接口
public interface VideoPlayer {
  String fileType = null;
  String filePath = null;
  public void play();
}
