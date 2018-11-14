# -*- coding: UTF-8 -*-
# ???
import smtplib
from email.mime.text import MIMEText
from email.header import Header

# 第三方 SMTP 服务
mail_host="smtp.???.com"  #设置服务器
mail_user="mktest???"    #用户名
mail_pass="mktest???"   #口令


sender = 'mktest???@???.com'
receivers = ['mktest???@???.com']  # 接收邮件

message = MIMEText('hello world', 'plain')
message['From'] = Header("mktest???@???.com")
message['To'] =  Header("mktest???@???.com")

subject = 'Hello world'
message['Subject'] = Header(subject)


try:
    smtpObj = smtplib.SMTP()
    smtpObj.connect(mail_host, 25)    # 25 为 SMTP 端口号
    smtpObj.login(mail_user,mail_pass)
    print(message.as_string())
    smtpObj.sendmail(sender, receivers, message.as_string())
    print "邮件发送成功"
except smtplib.SMTPException as e:
    print str(e)
    print "Error: 无法发送邮件"

