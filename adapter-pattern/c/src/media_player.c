#include "func.h"

/* 通用视频播放接口 */

// 设置播放器的文件格式
void set_player_file_type(MediaPlayer *player, char *file_type)
{
  strncpy(player->file_type, file_type, 20);
}

// 设置播放器的文件路径
void set_player_file_path(MediaPlayer *player, char *file_path)
{
  strncpy(player->file_path, file_path, 1000);
}