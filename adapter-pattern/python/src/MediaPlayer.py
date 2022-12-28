# -*- coding: utf-8 -*-
"""
@author: jarry
"""

class MediaPlayer():

    def __init__(self, file_type, file_path):
        self.file_type = file_type
        self.file_path = file_path

    def play(self, ):
        print('MediaPlayer fileType:' + self.file_type + ' | filePath:' +
              self.file_path)
        print('MediaPlayer::play()')

    def set_file_type(self, file_type):
        self.file_type = file_type

    def set_file_path(self, file_path):
        self.file_path = file_path
