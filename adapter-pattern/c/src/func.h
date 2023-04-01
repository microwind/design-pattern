#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 通用视频播放接口，供各种播放器实现
typedef struct MediaPlayer
{
    char file_type[20];
    char file_path[1000];
    void (*set_file_type)(struct MediaPlayer *player, char *file_type);
    void (*set_file_path)(struct MediaPlayer *player, char *file_path);
    void (*play)(struct MediaPlayer *player);
} MediaPlayer;
void set_player_file_type(MediaPlayer *player, char *file_type);
void set_player_file_path(MediaPlayer *player, char *file_path);

// mp4播放器
typedef struct Mp4Player
{
    char file_type[20];
    char file_path[1000];
    void (*set_file_type)(struct MediaPlayer *player, char *file_type);
    void (*set_file_path)(struct MediaPlayer *player, char *file_path);
    void (*play)(struct Mp4Player *player);
} Mp4Player;
Mp4Player *mp4_player_constructor(char *file_type, char *file_path);

// audio播放器
typedef struct AudioPlayer
{
    char file_type[20];
    char file_path[1000];
    void (*set_file_type)(struct MediaPlayer *player, char *file_type);
    void (*set_file_path)(struct MediaPlayer *player, char *file_path);
    void (*play)(struct AudioPlayer *player);
} AudioPlayer;
AudioPlayer *audio_player_constructor(char *file_type, char *file_path);

// hls播放器
typedef struct HlsPlayer
{
    char file_type[20];
    char file_path[1000];
    void (*set_file_type)(char *file_type);
    void (*set_file_path)(char *file_path);
    void (*play)(struct HlsPlayer *player);
} HlsPlayer;
HlsPlayer *hls_player_constructor(char *file_type, char *file_path);

// 适配器结构体，可以播放各种音频和视频，外部调用方式一样。
typedef struct PlayerAdapter
{
    char name[50];
    char media_type[20];
    void (* set_media_type)(struct PlayerAdapter *, char *);
    char file_type[20];
    void (* set_file_type)(struct PlayerAdapter *, char *);
    // 适配器里聚合了各种播放器
    Mp4Player *mp4_player;
    void (* set_mp4_player)(struct PlayerAdapter *, char *file_type, char *file_path);
    HlsPlayer *hls_player;
    void (* set_hls_player)(struct PlayerAdapter *, char *file_type, char *file_path);
    AudioPlayer *audio_player;
    void (* set_audio_player)(struct PlayerAdapter *, char *file_type, char *file_path);
    void (*play)(struct PlayerAdapter *);
    void (*init)(struct PlayerAdapter *, char *, char *, char *);
} PlayerAdapter;
PlayerAdapter *player_adapter_constructor(char *name);
