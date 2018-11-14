# -*- coding: utf-8 -*-
################################################################################
#
# Copyright (c) 2018 zll. All Rights Reserved
#
################################################################################
"""
This module provide the logging function.

Authors: zll
Date:    2018/10/22
"""

import os
import time

import logging
import logging.handlers

import zllutils


@zllutils.singleton
class ZLLLogger(object):
    """
    logger implementation
    not good, need improve!!
    """

    def __setfilelogger(self, logger):
        #logger.setLevel(logging.INFO)
        filename = time.strftime('%Y%m%d%H', time.localtime(time.time()))
        log_path = os.getcwd() + os.sep + self.__log_folder
        if not os.path.exists(log_path):
            os.makedirs(log_path)
        log_name = log_path + filename + '.log'
        logfile = log_name
        #fh = logging.FileHandler(logfile)
        fh = logging.handlers.TimedRotatingFileHandler(log_name,
                                                       when=self.__log_when,
                                                       backupCount=self.__log_backup)
        fh.setLevel(self.__log_level)
        formatter = logging.Formatter(self.__log_fmt)
        fh.setFormatter(formatter)
        logger.addHandler(fh)

    def __setconsolelog(self, logger):
        ch = logging.StreamHandler()
        ch.setLevel(self.__log_level)
        formatter = logging.Formatter(self.__log_fmt)
        ch.setFormatter(formatter)
        logger.addHandler(ch)

    def __init__(self, level=None, logFolder=None, logFmt=None, datefmt=None, when="D", backup=7):
        """@param level, see more info in logging
           @param logFolder, the relative folder according the cwd
           @param logFmt, see more info in logging
        """

        if level:
            self.__log_level = level
        else:
            self.__log_level = logging.INFO

        if logFolder:
            self.__log_folder = logFolder
        else:
            self.__log_folder = 'test/logs/'

        if logFmt:
            self.__log_fmt = logFmt
        else:
            self.__log_fmt = '%(asctime)s:[%(thread)d]-%(filename)s[line:%(lineno)d](%(levelname)s): %(message)s'

        if datefmt:
            self.__log_datefmt = datefmt
        else:
            self.__log_datefmt = "%m-%d %H:%M:%S"

        self.__log_when = when
        self.__log_backup = backup

        self.__logger = logging.getLogger()

        self.__logger.setLevel(self.__log_level)
        self.__setfilelogger(self.__logger)
        self.__setconsolelog(self.__logger)

    def getLogger(self):
        return self.__logger;

if __name__ == "__main__":
    myLogger = ZLLLogger()
    myLogger2 = ZLLLogger()
    if myLogger != myLogger2:
        print("error .....")


    myLogger.getLogger().debug("debug msg")
    myLogger.getLogger().info("info msg")
    myLogger.getLogger().warning("warning msg")
    myLogger.getLogger().error("error msg")

