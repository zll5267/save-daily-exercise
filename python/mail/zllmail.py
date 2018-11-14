# -*- coding: UTF-8 -*-
################################################################################
#
# Copyright (c) 2018 zll. All Rights Reserved
#
################################################################################
"""
This module provide the send mail function.

Authors: zll
Date:    2018/11/13
"""

import smtplib
import poplib
import email
from email.mime.text import MIMEText
from email.header import Header
from email.parser import Parser
from email.header import decode_header
from email.utils import parseaddr

import zlllogger
import zllutils

# ??? update first
MAGIC_NUM="???"
DEFAULT_SMTP_HOST="smtp." + MAGIC_NUM + ".com"
DEFAULT_POP3_HOST="pop." + MAGIC_NUM + ".com"
DEFAULT_USER="mktest" + MAGIC_NUM
DEFAULT_PASS="mktest" + MAGIC_NUM
DEFAULT_MAIL="mktest" + MAGIC_NUM + "@" + MAGIC_NUM + ".com"

@zllutils.singleton
class ZLLMail(object):

    def __init__(self, mail_host = "", mail_user = "", mail_pass = ""):
        '''
        mail_host: the mail server, default is smtp.???.com
                   if this param set, the other two also need set
        mail_user: the user for the @mail_host
        mail_pass: the pass for the user @mail_user on @mail_host
        '''
        if not mail_host:
            # the 3rd SMTP server
            self.__mail_host = DEFAULT_SMTP_HOST #server
            self.__mail_user = DEFAULT_USER #username
            self.__mail_pass = DEFAULT_PASS #passwd
        else:
            self.__mail_host = mail_host  #server
            self.__mail_user = mail_user  #username
            self.__mail_pass = mail_pass  #passwd
        self.__logger = zlllogger.ZLLLogger().getLogger()

    def send(self, sender, receivers, message):
        '''
         sender: the sender mail address
         receivers: the receivers' addresses, it's a list
         message: type of email.mime.text.MIMEText
         e.g.
             sender = 'xxxx@xxx.com'
             receivers = ['xxx@xxx.com']  # 接收邮件

             message = MIMEText('hello world', 'plain')
             message['From'] = Header("xxx@xxx.com")
             message['To'] =  Header("xxx@xxx.com")

             subject = 'Hello world'
             message['Subject'] = Header(subject)

        '''
        try:
            smtpObj = smtplib.SMTP()
            smtpObj.connect(self.__mail_host, 25)    # 25 port of SMTP
            smtpObj.login(self.__mail_user,self.__mail_pass)
            self.__logger.info(message.as_string())
            smtpObj.sendmail(sender, receivers, message.as_string())
            self.__logger.info("send mail success!")
        except smtplib.SMTPException as e:
            self.__logger.info(e)

    def send_ssl(self, sender, receivers, message):
        '''
         send by ssl transaction
         sender: the sender mail address
         receivers: the receivers' addresses, it's a list
         message: type of email.mime.text.MIMEText
         e.g.
             sender = 'xxx@xxx.com'
             receivers = ['xxx@xxx.com']  # 接收邮件

             message = MIMEText('hello world', 'plain')
             message['From'] = Header("xxx@xxx.com")
             message['To'] =  Header("xxx@xxx.com")

             subject = 'Hello world'
             message['Subject'] = Header(subject)

        '''
        try:
            smtpObj = smtplib.SMTP_SSL()
            #smtpObj.set_debuglevel(1)
            smtpObj.connect(self.__mail_host, 465)    # 465 port of SMTP ssl
            smtpObj.login(self.__mail_user,self.__mail_pass)
            self.__logger.info(message.as_string())
            smtpObj.sendmail(sender, receivers, message.as_string())
            self.__logger.info("send mail success!")
        except smtplib.SMTPException as e:
            self.__logger.info(e)

    def __guess_charset(self, msg):
        charset = msg.get_charset()
        if charset is None:
            content_type = msg.get('Content-Type', '').lower()
            pos = content_type.find('charset=')
            if pos >= 0:
                charset = content_type[pos + 8:].strip()
        return charset

    def __decode_str(self,s):
        value, charset = decode_header(s)[0]
        if charset:
            value = value.decode(charset)
        return value

    def __print_info(self, msg, indent=0):
        if indent == 0:
            for header in ['From', 'To', 'Subject']:
                value = msg.get(header, '')
                if value:
                    if header=='Subject':
                        value = self.__decode_str(value)
                    else:
                        hdr, addr = parseaddr(value)
                        name = self.__decode_str(hdr)
                        value = u'%s <%s>' % (name, addr)
                print('%s%s: %s' % ('  ' * indent, header, value))
        if (msg.is_multipart()):
            parts = msg.get_payload()
            for n, part in enumerate(parts):
                print('%spart %s' % ('  ' * indent, n))
                print('%s--------------------' % ('  ' * indent))
                print_info(part, indent + 1)
        else:
            content_type = msg.get_content_type()
            if content_type=='text/plain' or content_type=='text/html':
                content = msg.get_payload(decode=True)
                charset = self.__guess_charset(msg)
                if charset:
                    content = content.decode(charset)
                print('%sText: %s' % ('  ' * indent, content + '...'))
            else:
                print('%sAttachment: %s' % ('  ' * indent, content_type))

    def recv_pop3(self, user='', password='', pop3_server='', mail_num=1):
        '''
            get mails from the server by pop3
            user: the user on the @pop3_server
                if user set, the other paramers also need values
            password: the password for the @user
            pop3_server: the mail server
            mail_num: how many newest mails need to read
        '''
        if not user:
            user = DEFAULT_USER
            password = DEFAULT_PASS
            pop3_server = DEFAULT_POP3_HOST
        server = poplib.POP3(pop3_server)
        #server.set_debuglevel(1)
        self.__logger.info(server.getwelcome())
        # authorize:
        server.user(user)
        server.pass_(password)
        self.__logger.info('Messages: %s. Size: %s' % server.stat())
        resp, mails, octets = server.list()
        # the mail index start from 1, and the lastest has the biggest index:
        for i in range(len(mails) + 1)[mail_num*-1:]:
            resp, lines, octets = server.retr(i)
            # parse the mail:
            msg = Parser().parsestr('\r\n'.join(lines))
            # print the mail info:
            self.__print_info(msg)
            # delete the mail from the server:
            # server.dele(i)
        # close the connection:
        server.quit()

if __name__ == "__main__":
    mymail = ZLLMail()

    sender = DEFAULT_MAIL
    receivers = [DEFAULT_MAIL]  # receiver

    message = MIMEText('hello world, nihao', 'plain')
    message['From'] = Header(DEFAULT_MAIL)
    message['To'] =  Header(DEFAULT_MAIL)

    subject = 'Hello world'
    message['Subject'] = Header(subject)

    #mymail.send(sender, receivers, message)
    #mymail.send_ssl(sender, receivers, message)
    mymail.recv_pop3()


