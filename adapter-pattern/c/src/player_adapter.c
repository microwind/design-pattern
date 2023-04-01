#include "func.h"

/* 适配器类，可以播放各种音频和视频，外部调用方式一样。 */

// 模拟构造函数，初始化时声明具体播放器
void player_adapter_init(PlayerAdapter *adapter, char *media_type, char *file_type, char *file_path)
{
  strncpy(adapter->media_type, media_type, 20);
  strncpy(adapter->file_type, file_type, 20);
  if (strcmp(media_type, "audio") == 0)
  {
    adapter->set_audio_player(adapter, file_type, file_path);
  }
  else if (strcmp(file_type, "mp4") == 0)
  {
    adapter->set_mp4_player(adapter, file_type, file_path);
  }
  else if (strcmp(file_type, "hls") == 0)
  {
    adapter->set_hls_player(adapter, file_type, file_path);
  }
}

// 设置媒体类型
void set_adapter_media_type(struct PlayerAdapter *adapter, char *media_type)
{
  strncpy(adapter->media_type, media_type, 20);
}

// 设置文件格式
void set_adapter_file_type(struct PlayerAdapter *adapter, char *file_type)
{
  strncpy(adapter->file_type, file_type, 20);
}

// 设置音频播放器
void set_adapter_audio_player(PlayerAdapter *adapter, char *file_type, char *file_path)
{
  if (adapter->audio_player == NULL)
  {
    adapter->audio_player = audio_player_constructor(file_type, file_path);
  }
  else
  {
    adapter->audio_player->set_file_type((MediaPlayer *)adapter->audio_player, file_type);
    adapter->audio_player->set_file_path((MediaPlayer *)adapter->audio_player, file_path);
  }
}

// 设置Mp4播放器
void set_adapter_mp4_player(PlayerAdapter *adapter, char *file_type, char *file_path)
{
  if (adapter->mp4_player == NULL)
  {
    adapter->mp4_player = mp4_player_constructor(file_type, file_path);
  }
  else
  {
    set_player_file_type((MediaPlayer *)adapter->mp4_player, file_type);
    set_player_file_path((MediaPlayer *)adapter->mp4_player, file_path);
  }
}

// 设置hls播放器
void set_adapter_hls_player(PlayerAdapter *adapter, char *file_type, char *file_path)
{
  if (adapter->hls_player == NULL)
  {
    adapter->hls_player = hls_player_constructor(file_type, file_path);
  }
  else
  {
    set_player_file_type((MediaPlayer *)adapter->hls_player, file_type);
    set_player_file_path((MediaPlayer *)adapter->hls_player, file_path);
  }
}

// 适配接口里的通用play函数，适配不同媒体文件
void player_adapter_play(PlayerAdapter *adapter)
{
  printf("\r\n PlayerAdapter::play() [adapter->name=%s, media_type=%s file_type=%s]",
         adapter->name, adapter->media_type, adapter->file_type);

  if (strcmp(adapter->media_type, "audio") == 0)
  {
    adapter->audio_player->play(adapter->audio_player);
  }
  else if (strcmp(adapter->file_type, "mp4") == 0)
  {
    adapter->mp4_player->play(adapter->mp4_player);
  }
  else if (strcmp(adapter->file_type, "hls") == 0)
  {
    adapter->hls_player->play(adapter->hls_player);
  }
  else
  {
    printf("The media is not support. [media_type=%s, file_type=%s]", adapter->media_type, adapter->file_type);
  }
}

// 适配器的构造函数
PlayerAdapter *player_adapter_constructor(char *name)
{
  printf("\r\n player_adapter_constructor() [name=%s]", name);
  PlayerAdapter *adapter = (PlayerAdapter *)malloc(sizeof(PlayerAdapter));
  strncpy(adapter->name, name, 20);
  adapter->audio_player = NULL;
  adapter->mp4_player = NULL;
  adapter->hls_player = NULL;
  adapter->set_media_type = &set_adapter_media_type;
  adapter->set_file_type = &set_adapter_file_type;
  adapter->set_mp4_player = &set_adapter_mp4_player;
  adapter->set_hls_player = &set_adapter_hls_player;
  adapter->set_audio_player = &set_adapter_audio_player;
  adapter->play = &player_adapter_play;
  adapter->init = &player_adapter_init;
  return adapter;
}