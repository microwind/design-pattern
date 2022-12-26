package src;

// AudioPlayer支持多种音频格式播放，相对简单，在同一个类实现
public class AudioPlayer implements VideoPlayer {
  private String fileType;
  private String filePath;

  public AudioPlayer(String fileType, String filePath) {
    this.fileType = fileType;
    this.filePath = filePath;
  }

  public void play() {
    System.out.println("AudioPlayer fileType:" + fileType + " | filePath:" + filePath);
    if (fileType.equals("mp3")) {
      System.out.println("AudioPlayer::play() mp3");
    } else if (fileType.equals("mp4")) {
      System.out.println("AudioPlayer::play() mp4");
    }
  }

  public void setFileType(String fileType) {
    this.fileType = fileType;
  }

  public void setFilePath(String filePath) {
    this.filePath = filePath;
  }
}
