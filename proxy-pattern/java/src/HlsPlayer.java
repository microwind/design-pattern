package src;

// HlsPlayer播放器实现了视频接口
public class HlsPlayer implements VideoPlayer {
  String fileType = null;
  String filePath = null;

  public HlsPlayer(String fileType, String filePath) {
    this.fileType = fileType;
    this.filePath = filePath;
  }

  public void play() {
    System.out.println("HlsPlayer path:" + filePath);
    System.out.println("HlsPlayer::play()");
  }
}
