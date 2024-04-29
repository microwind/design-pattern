#include "../src/func.h"

int main(void)
{
  printf("test start:\r\n");
  /**
   * 适配器模式是当调用方需需调用不同功能，但接口并不兼容时，
   * 这时候可通过一个适配器类来做适配，让调用方通过适配类再去调用各个对象的功能。
   * 调用方只知道适配器，而不知道后面的其他对象。
   */

  // // mp4播放
  PlayerAdapter *player_adapter1 = player_adapter_constructor("adapter1");
  player_adapter1->init(player_adapter1, "video", "mp4", "d:/video.mp4");
  // 播放视频
  player_adapter1->play(player_adapter1);
  // 复用适配器实例，设置音频播放器，Mp4格式
  player_adapter1->set_media_type(player_adapter1, "audio");
  player_adapter1->set_file_type(player_adapter1, "mp4");
  player_adapter1->set_audio_player(player_adapter1, "mp4", "d:/audio.mp4");
  // 播放音频
  player_adapter1->play(player_adapter1);

  // hls播放
  PlayerAdapter *player_adapter2 = player_adapter_constructor("adapter2");
  player_adapter2->init(player_adapter2, "video", "hls", "http://video.m3u8");
  player_adapter2->play(player_adapter2);

  // mp3播放
  PlayerAdapter *player_adapter3 = player_adapter_constructor("adapter3");
  player_adapter3->init(player_adapter3, "audio", "mp3", "d:/audio.mp3");
  player_adapter3->play(player_adapter3);

  // mp4音频播放
  PlayerAdapter *player_adapter4 = player_adapter_constructor("adapter3");
  player_adapter4->init(player_adapter4, "audio", "mp4", "d:/audio.mp4");
  player_adapter4->play(player_adapter4);
  // 复用实例播hls视频
  player_adapter4->set_media_type(player_adapter4, "video");
  player_adapter4->set_file_type(player_adapter4, "hls");
  player_adapter4->set_hls_player(player_adapter4, "hls", "d:/video.m3u8");
  player_adapter4->play(player_adapter4);

  return 0;
}

// jarry@jarrys-MacBook-Pro c % gcc src/*.c test/test.c
// jarry@jarrys-MacBook-Pro c % ./a.out 
/**
test start:

 player_adapter_constructor() [name=adapter1]
 PlayerAdapter::play() [adapter->name=adapter1, media_type=video file_type=mp4]
 Mp4Player::play() [file_type=mp4, file_path="d:/video.mp4]
 PlayerAdapter::play() [adapter->name=adapter1, media_type=audio file_type=mp4]
 AudioPlayer::play() [file_type=mp4, file_path="d:/audio.mp4]
 player_adapter_constructor() [name=adapter2]
 PlayerAdapter::play() [adapter->name=adapter2, media_type=video file_type=hls]
 HlsPlayer::play() [file_type=hls, file_path="http://video.m3u8]
 player_adapter_constructor() [name=adapter3]
 PlayerAdapter::play() [adapter->name=adapter3, media_type=audio file_type=mp3]
 AudioPlayer::play() [file_type=mp3, file_path="d:/audio.mp3]
 player_adapter_constructor() [name=adapter3]
 PlayerAdapter::play() [adapter->name=adapter3, media_type=audio file_type=mp4]
 AudioPlayer::play() [file_type=mp4, file_path="d:/audio.mp4]
 PlayerAdapter::play() [adapter->name=adapter3, media_type=video file_type=hls]
 HlsPlayer::play() [file_type=hls, file_path="d:/video.m3u8]%
 */