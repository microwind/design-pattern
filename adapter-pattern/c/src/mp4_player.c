#include "func.h"

/* 具体播放器实现类 */

// mp4播放动作
void mp4_player_play(Mp4Player *player)
{
  printf("\r\n Mp4Player::play() [file_type=%s, file_path=\"%s]",
         player->file_type, player->file_path);
  // mp4 playing
}

// Mp4Player的构造函数
Mp4Player *mp4_player_constructor(char *file_type, char *file_path)
{
  MediaPlayer *player = (MediaPlayer *)malloc(sizeof(MediaPlayer));
  strncpy(player->file_type, file_type, 20);
  strncpy(player->file_path, file_path, 1000);
  player->set_file_type = &set_player_file_type;
  player->set_file_path = &set_player_file_path;
  Mp4Player *mp4_player = (Mp4Player *)player;
  mp4_player->play = &mp4_player_play;
  return mp4_player;
}