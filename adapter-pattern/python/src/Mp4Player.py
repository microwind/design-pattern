# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.MediaPlayer import MediaPlayer


class Mp4Player(MediaPlayer):

    def play(self, ):
        print('Mp4Player file_type:' + self.file_type + ' | file_path:' +
              self.file_path)
        print('Mp4Player::play()')