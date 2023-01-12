import { PlayerAdapter } from '../src/PlayerAdapter.js'

export function test() {

  /**
   * 适配器模式是当调用方需需调用不同功能，但接口并不兼容时，
   * 这时候可通过一个适配器类来做适配，让调用方通过适配类再去调用各个对象的功能。
   * 调用方只知道适配器，而不知道后面的其他对象。
   */

  // mp4播放
  const playerAdapter1 = new PlayerAdapter('video', 'mp4', 'd:/video.mp4')
  playerAdapter1.play()
  // 复用实例播音频
  playerAdapter1.playBy('audio', 'mp4', 'd:/audio.mp4')

  // hls播放
  const playerAdapter2 = new PlayerAdapter('video', 'hls', 'http://video.m3u8')
  playerAdapter2.play()

  // mp3播放
  const playerAdapter3 = new PlayerAdapter('audio', 'mp3', 'd:/audio.mp3')
  playerAdapter3.play()

  // mp4音频播放
  const playerAdapter4 = new PlayerAdapter('audio', 'mp4', 'd:/audio.mp4')
  playerAdapter4.play()
  // 复用实例播视频
  playerAdapter4.playBy('video', 'hls', 'd:/video.m3u8')
}

// 执行测试
;(function () {
  console.log('test start:')
  test()
})()
/**
// npm run
jarry@jarrys-MacBook-Pro js % npm run test
// or node execution
jarry@jarrys-MacBook-Pro js % node test/test.js
test start:
Mp4Player fileType:mp4 | filePath:d:/video.mp4
Mp4Player::play()
AudioPlayer fileType:mp4 | filePath:d:/audio.mp4
AudioPlayer::play()
AudioPlayer::play() mp4
HlsPlayer fileType:hls | filePath:http://video.m3u8
HlsPlayer::play()
AudioPlayer fileType:mp3 | filePath:d:/audio.mp3
AudioPlayer::play()
AudioPlayer::play() mp3
AudioPlayer fileType:mp4 | filePath:d:/audio.mp4
AudioPlayer::play()
AudioPlayer::play() mp4
HlsPlayer fileType:hls | filePath:d:/video.m3u8
HlsPlayer::play()
*/
