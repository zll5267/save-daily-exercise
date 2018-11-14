# -*- coding: utf-8 -*-

import time
import zlllogger

if __name__ == '__main__':
    while True:
        logger = zlllogger.ZLLLogger().getLogger()
        logger.info("test screen")
        time.sleep(2)


