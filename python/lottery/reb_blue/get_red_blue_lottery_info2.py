# -*- coding: utf-8 -*-
import datetime
import time
import re
import bs4
import requests
import json
import sqlite3

import zlllogger

__logger = zlllogger.ZLLLogger().getLogger()

def get_all_info():
    #code + link
    conn = sqlite3.connect('redblue.db')
    #CREATE TABLE kaijiang500_rb_info(code primary key not null, detaillink text not null);
    insert_str = 'insert into kaijiang500_rb_info(code, detaillink) values (?,?)'

    http_url = "http://kaijiang.500.com/shtml/ssq/13075.shtml"
    res = requests.get(http_url)
    res.encoding = 'gb2312'
    soup = bs4.BeautifulSoup(res.text, 'html.parser')
    codes_array = soup.select(".iSelectBox")[0].select("div")[0].select("a")
    for code_item in codes_array:
        __logger.info(code_item)
        code = code_item.text.strip()
        code_link = code_item["href"]
        conn.execute(insert_str, (code, code_link))
        conn.commit()

    conn.close()

def get_lottery_info_url(connn, last_code):
    url = ""
    code = ""
    if conn:
        sql_str = "select min(code) from kaijiang500_rb_info where code > (?);"
        cursor = conn.execute(sql_str, (last_code,))
        for row in cursor:
            if row[0]:
                if last_code < row[0]:
                    code = row[0]
#if last_code == '03001':
#            code = last_code
        url = ("http://kaijiang.500.com/shtml/ssq/%s.shtml" % code) 
    else:
        __logger.error("conn is not open")
    return (url, code)

def insert_new_item(conn, values):
    insert_str = ('insert into kaijiang500_redblue('
                                      'code, blue, red, date, sales, poolmoney,'
                                      'grade1number, grade1money,'
                                      'grade2number, grade2money,'
                                      'grade3number, grade3money,'
                                      'grade4number, grade4money,'
                                      'grade5number, grade5money,'
                                      'grade6number, grade6money,'
                                      'detailslink, sequence_balls,' 
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

__LAST_CODE = '03001'

def get_last_code():
    global __LAST_CODE
    if __LAST_CODE == '03001':
        query_str = 'select max(code) from kaijiang500_redblue;'
        cursor = conn.execute(query_str)
        last_code = ''

        for row in cursor:
            if row[0]:
                __LAST_CODE = row[0][2:]
    return __LAST_CODE

def set_last_code(new_code):
    global __LAST_CODE
    __LAST_CODE = new_code

def get_max_date(conn):
    query_str = 'select max(date) from kaijiang500_redblue;'
    cursor = conn.execute(query_str)
    last_date = ''

    for row in cursor:
        if row[0]:
            if last_date < row[0]:
                last_date = row[0]
    return last_date

def get_from_kaijiang500(conn):
    
    last_date_str = get_max_date(conn)
    __logger.info("last_date:" + last_date_str)
    if last_date_str:
        last_date_dt = datetime.datetime.strptime(last_date_str, '%Y-%m-%d') 
        now_dt = datetime.datetime.now()
        if last_date_dt >= now_dt:
            __logger.warning("reach latested day:" + now_dt.strftime('%Y-%m-%d'))
            return False

    last_code = get_last_code()
    __logger.info("last_code:" + last_code)
    lottery_info_url = ""
    (lottery_info_url, last_code) = get_lottery_info_url(conn, last_code)
    __logger.info(lottery_info_url)
    if not last_code:
        __logger.warning("all code finished!")
        return False
    set_last_code(last_code)
    code = "20" + last_code
    detailslink = lottery_info_url
    videolink = ''
    grade1detail = ''

    lottery_response = requests.get(lottery_info_url)
    lottery_response.encoding = 'gb2312'
    lottery_res_text = lottery_response.text.encode("utf-8")
    soup = bs4.BeautifulSoup(lottery_res_text, 'html.parser')

    __logger.debug(lottery_response)
    __logger.debug(lottery_response.text)

    ball_box01 = soup.select(".ball_box01")[0]
    ball_reds = ball_box01.select(".ball_red")
    reds = []
    for ball_red in ball_reds:
        reds.append(ball_red.text.strip())
    red = ",".join(reds)

    ball_blue = ball_box01.select(".ball_blue")[0]
    blue = ball_blue.text.strip()

    date_str = soup.select(".td_title01")[0].select(".span_right")[0].text.strip()
    __logger.info(date_str)
    re_res = re.search("开奖日期：(.*) 兑奖截止日期", date_str.encode('utf-8'))
    #date_str = re_res[1] only work in python3
    date_str = re_res.group(1).strip()

    date_dt = datetime.datetime.strptime(date_str, "%Y年%m月%d日")
    date = date_dt.strftime('%Y-%m-%d')

    money_tds = soup.select(".kj_tablelist02")[0].select(".cfont1")
    __logger.info(money_tds[0].text.strip()) 
    __logger.info(money_tds[1].text.strip())
    sales = int(money_tds[0].text.strip().replace(",", "").replace("--", "0")[0:-1])
    poolmoney = int(money_tds[1].text.strip().replace(",", "").replace("--", "0")[0:-1])

    grade1number = grade1money = 0                                                          
    grade2number = grade2money = 0                                                          
    grade3number = grade3money = 0                                                          
    grade4number = grade4money = 0                                                          
    grade5number = grade5money = 0                                                          
    grade6number = grade6money = 0

    table_trs = soup.select(".kj_tablelist02")[1].select("tr")
    for table_tds in table_trs[2:-1]:# remove header and footer
        tds = table_tds.select("td")
        (td1,td2,td3) = tds
        (typename, typenumber, typemoney) = (td1.text.strip(), td2.text.strip(), td3.text.strip())
        print((typename, typenumber, typemoney))
        typename = typename.encode("utf-8");
        typenumber = typenumber.encode("utf-8")
        typemoney = typemoney.replace(",", "").encode("utf-8")
        if typenumber == "--":
            typenumber = '0'
        if typemoney == "--":
            typemoney = '0'
        __logger.info("typename:" + typename)
        __logger.info("typenumber:" + typenumber)
        __logger.info("typemoney:" + typemoney)
        if typename == '一等奖':
            grade1number = int(typenumber)
            grade1money = int(typemoney)
        elif typename == '二等奖':
            grade2number = int(typenumber)
            grade2money = int(typemoney)
        elif typename == '三等奖':
            grade3number = int(typenumber)
            grade3money = int(typemoney)
        elif typename == '四等奖':
            grade4number = int(typenumber)
            grade4money = int(typemoney)
        elif typename == '五等奖':
            grade5number = int(typenumber)
            grade5money = int(typemoney)
        elif typename == '六等奖':
            grade6number = int(typenumber)
            grade6money = int(typemoney)
        else:
            print("unknown type")
    
    sequence_balls_td = soup.select(".kj_tablelist02")[0].select("tr")[1].select("tr")[1].select("td")[1]
    sequence_balls = sequence_balls_td.text.strip().replace(" ", ",")

    __logger.info("code:" + code) 
    __logger.info("blue:" + blue) 
    __logger.info("red:" + red) 
    __logger.info("date:" + date) 
    __logger.info("sales:%d" % sales) 
    __logger.info("poolmoney:%d" % poolmoney) 
    __logger.info("一等奖: 中奖数:%d,奖金:%d" % (grade1number, grade1money)) 
    __logger.info("二等奖: 中奖数:%d,奖金:%d" % (grade2number, grade2money)) 
    __logger.info("三等奖: 中奖数:%d,奖金:%d" % (grade3number, grade3money)) 
    __logger.info("四等奖: 中奖数:%d,奖金:%d" % (grade4number, grade4money)) 
    __logger.info("五等奖: 中奖数:%d,奖金:%d" % (grade5number, grade5money)) 
    __logger.info("六等奖: 中奖数:%d,奖金:%d" % (grade6number, grade6money)) 
    __logger.info("detailslink:" + detailslink) 
    __logger.info("sequence_balls:" + sequence_balls) 

    values = (code, blue, red, date, sales, poolmoney,
                      grade1number, grade1money,
                      grade2number, grade2money,
                      grade3number, grade3money,
                      grade4number, grade4money,
                      grade5number, grade5money,
                      grade6number, grade6money,
                      detailslink,  sequence_balls, 
                      grade1detail)
    insert_new_item(conn, values)

    return True

if __name__ == "__main__":
    conn = sqlite3.connect('redblue.db')
    #get_all_info()
    #code = '11153'
    #(url, code) = get_lottery_info_url(conn, code)
    #print(url, code)
    while True:
        get_from_kaijiang500(conn)
        time.sleep(2)
    conn.close()
