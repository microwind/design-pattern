# -*- coding: utf-8 -*-
"""
@author: jarry
"""
import sys
import os

os_path = os.getcwd()
sys.path.append(os_path)

from src.PlayerAdapter import PlayerAdapter
from src.PlayerAdapter import PlayerAdapter


def test():
    # mp4播放
    player_adapter1 = PlayerAdapter('video', 'mp4', 'd:/video.mp4')
    player_adapter1.play_default()
    # 复用实例播音频
    player_adapter1.play('audio', 'mp4', 'd:/audio.mp4')

    # hls播放
    player_adapter2 = PlayerAdapter('video', 'hls', 'http:#video.m3u8')
    player_adapter2.play_default()

    # mp3播放
    player_adapter3 = PlayerAdapter('audio', 'mp3', 'd:/audio.mp3')
    player_adapter3.play_default()

    # mp4音频播放
    player_adapter4 = PlayerAdapter('audio', 'mp4', 'd:/audio.mp4')
    player_adapter4.play_default()
    # 复用实例播视频
    player_adapter4.play('video', 'hls', 'd:/video.m3u8')


if __name__ == '__main__':
    print(__file__)
    print("test start:")
    test()
'''
jarry@jarrys-MacBook-Pro python % python -V
Python 2.7.16

jarry@jarrys-MacBook-Pro python % python test/test.py
test/test.py
test start:
('Mp4Player file_type:mp4 | file_path:d:/video.mp4',)
Mp4Player::play()
('AudioPlayer file_type:mp4 | file_path:d:/audio.mp4',)
AudioPlayer::play()
AudioPlayer::play() mp4
('HlsPlayer file_type:hls | file_path:http:#video.m3u8',)
HlsPlayer::play()
('AudioPlayer file_type:mp3 | file_path:d:/audio.mp3',)
AudioPlayer::play()
AudioPlayer::play() mp3
('AudioPlayer file_type:mp4 | file_path:d:/audio.mp4',)
AudioPlayer::play()
AudioPlayer::play() mp4
('HlsPlayer file_type:hls | file_path:d:/video.m3u8',)
HlsPlayer::play()
'''