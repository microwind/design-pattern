# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.MediaPlayer import MediaPlayer


class AudioPlayer(MediaPlayer):

    def __init__(self, file_type, file_path):
        self.file_type = file_type
        self.file_path = file_path

    def play(self, ):
        print('AudioPlayer file_type:' + self.file_type + ' | file_path:' +
              self.file_path)
        print('AudioPlayer::play()')
        if (self.file_type == 'mp3'):
            print('AudioPlayer::play() mp3')
        elif (self.file_type == 'mp4'):
            print('AudioPlayer::play() mp4')

    # def set_file_type(self, file_type):
    #     self.file_type = file_type

    # def set_file_path(self, file_path):
    #     self.file_path = file_path
