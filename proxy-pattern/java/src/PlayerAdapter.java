package src;

// 适配器类，可以播放各种音频和视频，外部调用方式一样
public class PlayerAdapter {

  private String mediaType;
  private String fileType;
  private String filePath;
  private VideoPlayer mp4Player;
  private VideoPlayer hlsPlayer;
  private AudioPlayer audioPlayer;

  public PlayerAdapter(String mediaType, String fileType, String filePath) {
    this.mediaType = mediaType;
    this.fileType = fileType;
    this.filePath = filePath;
    if (mediaType.equals("video")) {
      if (fileType.equals("mp4")) {
        mp4Player = new Mp4Player(fileType, filePath);
      } else if (fileType.equals("hls")) {
        hlsPlayer = new HlsPlayer(fileType, filePath);
      }
    } else if (mediaType.equals("audio")) {
      audioPlayer = new AudioPlayer(fileType, filePath);
    }
  }

  public void play() {
    if (this.mediaType.equals("audio")) {
      audioPlayer.play();
    } else if (this.mediaType.equals("video")) {
      if (this.fileType.equals("mp4")) {
        mp4Player.play();
      } else if (this.fileType.equals("hls")) {
        hlsPlayer.play();
      }
    }
  }

}
