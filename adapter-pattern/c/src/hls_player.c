#include "func.h"

/* 具体播放器实现类 */

void hls_player_play(HlsPlayer *player)
{
  printf("\r\n HlsPlayer::play() [file_type=%s, file_path=\"%s]",
         player->file_type, player->file_path);
  // hls playing
}

// HlsPlayer的构造函数
HlsPlayer *hls_player_constructor(char *file_type, char *file_path)
{
  MediaPlayer *player = (MediaPlayer *)malloc(sizeof(MediaPlayer));
  strncpy(player->file_type, file_type, 20);
  strncpy(player->file_path, file_path, 1000);
  player->set_file_type = &set_player_file_type;
  player->set_file_path = &set_player_file_path;
  HlsPlayer *hls_player = (HlsPlayer *)player;
  hls_player->play = &hls_player_play;
  return hls_player;
}