#!/usr/bin/python3

"""
Operator overriding practice
"""

class Number:
    def __init__(self, start):
        self.data = start
    def __sub__(self, other):
        return Number(self.data-other)

#X[in] -> __getitem__
class Indexer:
    def __getitem__(self, index):
        return index ** 2;
#X[b:e:s] -> __getitem__
class Slicer:
    data = [1, 2 ,3 ,4 ,5]
    def __getitem__(self, index):
        print('getitem:', index)
        return self.data[index]
    def __setitem__(self, index, value):
        self.data[index] = value

