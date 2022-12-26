package src;

// VideoPlayer支持视频/音频的格式播放接口，作为基础接口。
public interface VideoPlayer {
  String fileType = null;
  String filePath = null;
  public void play();
  public void setFileType(String fileType);
  public void setFilePath(String filePath);
}
