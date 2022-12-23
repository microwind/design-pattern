package src;

// HlsPlayer播放器实现了视频接口
public class Mp4Player implements VideoPlayer {
  String fileType = null;
  String filePath = null;

  public Mp4Player(String fileType, String filePath) {
    this.fileType = fileType;
    this.filePath = filePath;
  }

  public void play() {
    System.out.println("Mp4Player path:" + filePath);
    System.out.println("Mp4Player::play()");
  }
}
