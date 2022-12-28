package src;

// HlsPlayer播放器实现了视频接口
public class Mp4Player implements MediaPlayer {
  private String fileType;
  private String filePath;

  public Mp4Player(String fileType, String filePath) {
    this.fileType = fileType;
    this.filePath = filePath;
  }

  public void play() {
    System.out.println("Mp4Player fileType:" + fileType + " | filePath:" + filePath);
    System.out.println("Mp4Player::play()");
  }

  public void setFileType(String fileType) {
    this.fileType = fileType;
  }

  public void setFilePath(String filePath) {
    this.filePath = filePath;
  }
}
