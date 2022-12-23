package test;

import src.*;

public class Test {

  public static void start() {

    // Mp4播放
    PlayerAdapter playerAdapter1 = new PlayerAdapter("video", "mp4", "d:/video.mp4");
    playerAdapter1.play();

    // hls播放
    PlayerAdapter playerAdapter2 = new PlayerAdapter("video", "hls", "http://video.m3u8");
    playerAdapter2.play();

    // mp3播放
    PlayerAdapter playerAdapter3 = new PlayerAdapter("audio", "mp3", "d:/video.mp4");
    playerAdapter3.play();

    // mp4音频播放
    PlayerAdapter playerAdapter4 = new PlayerAdapter("audio", "mp4", "d:/video.mp4");
    playerAdapter4.play();
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
 * SingleObject::run()
 * SingletonLazy::run()
 * SingletonSafe::run()
 * SingletonInner::run()
 */