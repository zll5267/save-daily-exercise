# -*- coding: utf-8 -*-
################################################################################
#
# Copyright (c) 2018 zll, All Rights Reserved
#
################################################################################
"""
This module provide the utility functions.

Authors: zll
Date:    2018/10/22
"""


def singleton(cls):
    """
    used as decorator for singleton class
    """
    instances = {}
    def getinstance(*args,**kwargs):
        if cls not in instances:
            instances[cls] = cls(*args,**kwargs)
        return instances[cls]
    return getinstance

