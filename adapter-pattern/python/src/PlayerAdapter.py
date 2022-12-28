# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.MediaPlayer import MediaPlayer
from src.Mp4Player import Mp4Player
from src.HlsPlayer import HlsPlayer
from src.AudioPlayer import AudioPlayer


# 适配器是否继承基类可选。
# class PlayerAdapter(MediaPlayer):
class PlayerAdapter():

    def __init__(self, media_type, file_type, file_path):
        self.media_type = media_type
        self.file_type = file_type
        self.mp4_player = None
        self.hls_player = None
        self.audio_player = None
        if (media_type == 'video'):
            if (file_type == 'mp4'):
                self.set_mp4_player(file_type, file_path)
            elif (file_type == 'hls'):
                self.set_hls_player(file_type, file_path)

        elif (media_type == 'audio'):
            self.set_audio_player(file_type, file_path)

    def set_mp4_player(self, file_type, file_path):
        if self.mp4_player is None:
            self.mp4_player = Mp4Player(file_type, file_path)
        else:
            self.mp4_player.set_file_type(file_type)
            self.mp4_player.set_file_path(file_path)

    def set_hls_player(self, file_type, file_path):
        if (self.hls_player is None):
            self.hls_player = HlsPlayer(file_type, file_path)
        else:
            self.hls_player.set_file_type(file_type)
            self.hls_player.set_file_path(file_path)

    def set_audio_player(self, file_type, file_path):
        if (self.audio_player is None):
            self.audio_player = AudioPlayer(file_type, file_path)
        else:
            self.audio_player.set_file_type(file_type)
            self.audio_player.set_file_path(file_path)

    # 通用的适配接口
    def play_default(self):
        if (self.media_type == 'audio'):
            self.audio_player.play()
        elif (self.media_type == 'video'):
            if (self.file_type == 'mp4'):
                self.mp4_player.play()
            elif (self.file_type == 'hls'):
                self.hls_player.play()

    # 根据路径播放，可根据需要复用实例
    def play(self, media_type, file_type, file_path):

        if (media_type == 'audio'):
            self.set_audio_player(file_type, file_path)
            self.audio_player.play()
        elif (media_type == 'video'):
            if (file_type == 'mp4'):
                self.set_mp4_player(file_type, file_path)
                self.mp4_player.play()
            elif (file_type == 'hls'):
                self.set_hls_player(file_type, file_path)
                self.hls_player.play()
