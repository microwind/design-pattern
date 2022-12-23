package src;

// 适配器类，可以播放各种音频和视频，外部调用方式一样
public class PlayerAdapter {

  private String mediaType;
  private String fileType;
  private VideoPlayer mp4Player;
  private VideoPlayer hlsPlayer;
  private AudioPlayer audioPlayer;

  public PlayerAdapter(String mediaType, String fileType, String filePath) {
    this.mediaType = mediaType;
    this.fileType = fileType;
    if (mediaType.equals("video")) {
      if (fileType.equals("mp4")) {
        setMp4Player(fileType, filePath);
      } else if (fileType.equals("hls")) {
        setHlsPlayer(fileType, filePath);
      }
    } else if (mediaType.equals("audio")) {
      setAudioPlayer(fileType, filePath);
    }
  }

  public void setMp4Player(String fileType, String filePath) {
    if (mp4Player == null) {
      mp4Player = new Mp4Player(fileType, filePath);
    } else {
      mp4Player.setFileType(fileType);
      mp4Player.setFilePath(filePath);
    }
  }

  public void setHlsPlayer(String fileType, String filePath) {
    if (hlsPlayer == null) {
      hlsPlayer = new HlsPlayer(fileType, filePath);
    } else {
      hlsPlayer.setFileType(fileType);
      hlsPlayer.setFilePath(filePath);
    }
  }

  public void setAudioPlayer(String fileType, String filePath) {
    if (audioPlayer == null) {
      audioPlayer = new AudioPlayer(fileType, filePath);
    } else {
      audioPlayer.setFileType(fileType);
      audioPlayer.setFilePath(filePath);
    }
  }

  // 通用的适配接口
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

  // 根据路径播放，可根据需要复用实例
  public void play(String mediaType, String fileType, String filePath) {
    if (mediaType.equals("audio")) {
      setAudioPlayer(fileType, filePath);
      audioPlayer.play();
    } else if (mediaType.equals("video")) {
      if (fileType.equals("mp4")) {
        setMp4Player(fileType, filePath);
        mp4Player.play();
      } else if (fileType.equals("hls")) {
        setHlsPlayer(fileType, filePath);
        hlsPlayer.play();
      }
    }
  }

}
