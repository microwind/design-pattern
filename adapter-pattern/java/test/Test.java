package test;

import src.*;

public class Test {

  public static void start() {

    /**
     * 适配器模式是当调用方需需调用不同功能，但接口并不兼容时，
     * 这时候可通过一个适配器类来做适配，让调用方通过适配类再去调用各个对象的功能。
     * 调用方只知道适配器，而不知道后面的其他对象。
     */

    // mp4播放
    PlayerAdapter playerAdapter1 = new PlayerAdapter("video", "mp4", "d:/video.mp4");
    playerAdapter1.play();
    // 复用实例播音频
    playerAdapter1.play("audio", "mp4", "d:/audio.mp4");

    // hls播放
    PlayerAdapter playerAdapter2 = new PlayerAdapter("video", "hls", "http://video.m3u8");
    playerAdapter2.play();

    // mp3播放
    PlayerAdapter playerAdapter3 = new PlayerAdapter("audio", "mp3", "d:/audio.mp3");
    playerAdapter3.play();

    // mp4音频播放
    PlayerAdapter playerAdapter4 = new PlayerAdapter("audio", "mp4", "d:/audio.mp4");
    playerAdapter4.play();
    // 复用实例播视频
    playerAdapter4.play("video", "hls", "d:/video.m3u8");

  }

  public static void main(String[] args) {
    System.out.println("test start:");
    start();
  }

}

/**
 * 测试
 * jarry@jarrys-MacBook-Pro java % java --version
 * java 14.0.1 2020-04-14
 * Java(TM) SE Runtime Environment (build 14.0.1+7)
 * Java HotSpot(TM) 64-Bit Server VM (build 14.0.1+7, mixed mode, sharing)
 * 
 * jarry@jarrys-MacBook-Pro java % javac test/Test.java
 * jarry@jarrys-MacBook-Pro java % java test/Test
 * test start:
 * Mp4Player fileType:mp4 | filePath:d:/video.mp4
 * Mp4Player::play()
 * AudioPlayer fileType:mp4 | filePath:d:/audio.mp4
 * AudioPlayer::play() mp4
 * HlsPlayer fileType:hls | filePath:http://video.m3u8
 * HlsPlayer::play()
 * AudioPlayer fileType:mp3 | filePath:d:/audio.mp3
 * AudioPlayer::play() mp3
 * AudioPlayer fileType:mp4 | filePath:d:/audio.mp4
 * AudioPlayer::play() mp4
 * HlsPlayer fileType:hls | filePath:d:/video.m3u8
 * HlsPlayer::play()
 */