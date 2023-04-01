#include "func.h"

/* 具体播放器实现类 */

void audio_player_play(AudioPlayer *player)
{
  printf("\r\n AudioPlayer::play() [file_type=%s, file_path=\"%s]",
         player->file_type, player->file_path);
  // audio playing
}

// AudioPlayer的构造函数
AudioPlayer *audio_player_constructor(char *file_type, char *file_path)
{
  MediaPlayer *player = (MediaPlayer *)malloc(sizeof(MediaPlayer));
  strncpy(player->file_type, file_type, 20);
  strncpy(player->file_path, file_path, 1000);
  player->set_file_type = &set_player_file_type;
  player->set_file_path = &set_player_file_path;
  AudioPlayer *audio_player = (AudioPlayer *)player;
  audio_player->play = &audio_player_play;
  return audio_player;
}