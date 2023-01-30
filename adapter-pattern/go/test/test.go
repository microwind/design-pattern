package main

import (
  "fmt"

  "microwind/src"
)

// main包下的main入口方法
func main() {
  fmt.Println("test start:")
  /**
   * 适配器模式是当调用方需需调用不同功能，但接口并不兼容时，
   * 这时候可通过一个适配器类来做适配，让调用方通过适配类再去调用各个对象的功能。
   * 调用方只知道适配器，而不知道后面的其他对象。
   */

  // mp4播放
  var playerAdapter1 = &src.PlayerAdapter{}
  playerAdapter1.Init("video", "mp4", "d:/video.mp4")
  playerAdapter1.Play()
  // 复用实例播音频
  playerAdapter1.PlayBy("audio", "mp4", "d:/audio.mp4")

  // hls播放
  var playerAdapter2 = &src.PlayerAdapter{}
  playerAdapter2.Init("video", "hls", "http://video.m3u8")
  playerAdapter2.Play()

  // mp3播放
  var playerAdapter3 = &src.PlayerAdapter{}
  playerAdapter3.Init("audio", "mp3", "d:/audio.mp3")
  playerAdapter3.Play()

  // mp4音频播放
  var playerAdapter4 = &src.PlayerAdapter{}
  playerAdapter4.Init("audio", "mp4", "d:/audio.mp4")
  playerAdapter4.Play()
  // 复用实例播视频
  playerAdapter4.PlayBy("video", "hls", "d:/video.m3u8")
}

/**
jarry@jarrys-MacBook-Pro go % go build src/*.go
jarry@jarrys-MacBook-Pro go % go run test/test.go
test start:
Mp4Player FileType:mp4 | FilePath:d:/video.mp4
Mp4Player::Play()
AudioPlayer FileType:mp4 | FilePath:d:/audio.mp4
AudioPlayer::Play()
AudioPlayer::Play() mp4
HlsPlayer FileType:hls | FilePath:http://video.m3u8
HlsPlayer::Play()
AudioPlayer FileType:mp3 | FilePath:d:/audio.mp3
AudioPlayer::Play()
AudioPlayer::Play() mp3
AudioPlayer FileType:mp4 | FilePath:d:/audio.mp4
AudioPlayer::Play()
AudioPlayer::Play() mp4
HlsPlayer FileType:hls | FilePath:d:/video.m3u8
HlsPlayer::Play()
*/
