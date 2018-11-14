# -*- coding: utf-8 -*-
import datetime
import time
import bs4
import requests
import json
import sqlite3

import zlllogger

#test_url = "http://www.cwl.gov.cn/cwl_admin/kjxx/findDrawNotice?name=ssq&issueCount=&issueStart=&issueEnd=&dayStart=2017-10-17&dayEnd=2017-10-24&pageNo="
#print(test_url)
#GET /cwl_admin/kjxx/findDrawNotice?name=ssq&issueCount=&issueStart=&issueEnd=&dayStart=2017-10-17&dayEnd=2017-10-24&pageNo= HTTP/1.1
#Host: www.cwl.gov.cn
#Connection: keep-alive
#Accept: application/json, text/javascript, */*; q=0.01
#X-Requested-With: XMLHttpRequest
#User-Agent: Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.77 Safari/537.36
#Referer: http://www.cwl.gov.cn/kjxx/ssq/kjgg/
#Accept-Encoding: gzip, deflate
#Accept-Language: zh-CN,zh;q=0.9,en;q=0.8
#Cookie: UniqueID=5q7JVn93K38UsbDa1541768380988; Sites=_21; 21_vq=12

__logger = zlllogger.ZLLLogger().getLogger()

def get_lottery_info_url_between_date(start, end):
        return ("http://www.cwl.gov.cn/cwl_admin/kjxx/"
               "findDrawNotice?name=ssq&issueCount="
               "&issueStart=&issueEnd=&dayStart=" + start + 
               "&dayEnd="+ end + "&pageNo=")


def insert_new_item(conn, values):
    insert_str = ('insert into redblue('
                                      'code, blue, red, date, sales, poolmoney,'
                                      'grade1number, grade1money,'
                                      'grade2number, grade2money,'
                                      'grade3number, grade3money,'
                                      'grade4number, grade4money,'
                                      'grade5number, grade5money,'
                                      'grade6number, grade6money,'
                                      'detailslink, videolink,' 
                                      'grade1detail'
                                      ') values'
                                      '(?,?,?,?,?,?,'
                                      '?,?,'
                                      '?,?,'
                                      '?,?,'
                                      '?,?,'
                                      '?,?,'
                                      '?,?,'
                                      '?,?,'
                                      '?'
                                      ')')
    if conn:
        conn.execute(insert_str, values)
        conn.commit()
    else:
        __logger.error("conn is not open")

__LAST_DATE = '1999-12-31'

def get_last_date():
    global __LAST_DATE
    return __LAST_DATE

def set_last_date(new_date):
    global __LAST_DATE
    __LAST_DATE = new_date

def get_max_date(conn):
    query_str = 'select max(date) from redblue;'
    cursor = conn.execute(query_str)
    last_date = get_last_date()

    for row in cursor:
        if row[0]:
            if last_date < row[0]:
                last_date = row[0]
    return last_date

def test():
    conn = sqlite3.connect('redblue.db')
    
    last_date_str = get_max_date(conn)
    __logger.info("last_date:" + last_date_str)
    last_date_dt = datetime.datetime.strptime(last_date_str, '%Y-%m-%d') 
    start_dt = last_date_dt + datetime.timedelta(days=1)
    now_dt = datetime.datetime.now()
    if start_dt > now_dt:
        __logger.warning("reach latested day:" + now_dt.strftime('%Y-%m-%d'))
        return False

    dayStart = start_dt.strftime('%Y-%m-%d')
    stop_dt = start_dt + datetime.timedelta(days=7)
    dayEnd = stop_dt.strftime('%Y-%m-%d')
    __logger.info("start_date:" + dayStart + ";stop_date:" + dayEnd)
    lottery_info_url = get_lottery_info_url_between_date(dayStart, dayEnd)
    __logger.info(lottery_info_url)

    lottery_request_headers = { 
        "X-Requested-With": "XMLHttpRequest",
        "Referer": "http://www.cwl.gov.cn/kjxx/ssq/kjgg/",
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.77 Safari/537.36",
    }
    lottery_response = requests.get(lottery_info_url, headers=lottery_request_headers)

    __logger.debug(lottery_response)
    __logger.debug(lottery_response.text)

    lottery_info_json = json.loads(lottery_response.text)
#print(lottery_info_json)

    __logger.info("state:" + str(lottery_info_json['state']))
    __logger.info("message:" + (lottery_info_json['message']))
    countNum = lottery_info_json['countNum']
    __logger.info("countNum:" + str(countNum))

    if countNum > 0 :
        for item in lottery_info_json["result"]:
            name = item["name"]
            code = item["code"]
            detailsLink = "http://www.cwl.gov.cn" + item["detailsLink"]
            videoLink = "http://www.cwl.gov.cn" + item["videoLink"]
            date = item["date"][0:10] 
            red = item["red"]
            blue = item["blue"]
            sales = int(item["sales"])
            poolmoney = int(item["poolmoney"])
            grade1detail = content = item["content"]
            __logger.info(" name:" + name)
            __logger.info(" code:" + code)
            __logger.info(" detailsLink:" + detailsLink)
            __logger.info(" videoLink:" + videoLink)
            __logger.info(" date:" + date)
            __logger.info(" week:" + item["week"])
            __logger.info(" red:" + red)
            __logger.info(" blue:" + blue)
            __logger.info(" sales:%d" % sales)
            __logger.info(" poolmoney:%d" % poolmoney)
            __logger.info(" content:" + content)
            grade1number = grade1money = 0 
            grade2number = grade2money = 0 
            grade3number = grade3money = 0 
            grade4number = grade4money = 0 
            grade5number = grade5money = 0 
            grade6number = grade6money = 0 
            for prizegrade in item["prizegrades"]:
                prizetype = prizegrade["type"]
                prizenum = prizegrade["typenum"]
                prizemoney = prizegrade["typemoney"]
                __logger.info("  type:" + str(prizetype) 
                     + ";typenum:" + prizenum
                     + ";typemoney:" + prizemoney)
                if prizetype == 1:
                    grade1number = prizenum
                    grade1money = prizemoney 
                elif prizetype == 2:
                    grade2number = prizenum
                    grade2money = prizemoney 
                elif prizetype == 3:
                    grade3number = prizenum
                    grade3money = prizemoney 
                elif prizetype == 4:
                    grade4number = prizenum
                    grade4money = prizemoney 
                elif prizetype == 5:
                    grade5number = prizenum
                    grade5money = prizemoney 
                elif prizetype == 6:
                    grade6number = prizenum
                    grade6money = prizemoney 
            values = (code, blue, red, date, sales, poolmoney,
                      grade1number, grade1money,
                      grade2number, grade2money,
                      grade3number, grade3money,
                      grade4number, grade4money,
                      grade5number, grade5money,
                      grade6number, grade6money,
                      detailsLink, videoLink, 
                      grade1detail)
            insert_new_item(conn, values)
    else:
        set_last_date(dayEnd)

    conn.close()
    return True

if __name__ == "__main__":
    while(1):
        ret = test()
        if not ret:
            break
        else:
            time.sleep(3)

