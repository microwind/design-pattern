package src;

// HlsPlayer播放器实现了视频接口
public class HlsPlayer implements MediaPlayer {
  private String fileType;
  private String filePath;

  public HlsPlayer(String fileType, String filePath) {
    this.fileType = fileType;
    this.filePath = filePath;
  }

  public void play() {
    System.out.println("HlsPlayer fileType:" + fileType + " | filePath:" + filePath);
    System.out.println("HlsPlayer::play()");
  }

  public void setFileType(String fileType) {
    this.fileType = fileType;
  }

  public void setFilePath(String filePath) {
    this.filePath = filePath;
  }
}
