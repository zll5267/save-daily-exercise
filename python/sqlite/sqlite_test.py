#!/usr/bin/env python

import sqlite3

conn = sqlite3.connect('sqlite.db') # :memory create a db in memory
print("connect to database sqlite.db successfully")

##how to create a table
#conn.execute(''' CREATE TABLE STUDENT
#        (ID INT PRIMARY KEY NOT NULL,
#        NAME TEXT NOT NULL,
#        AGE INT NOT NULL,
#        ADDRESS CHAR(50));''')
#print("create table ok")

##insert value into student
#conn.execute("insert into student(id, name, age, address) values (1, 'wangwu', 13, 'china')")
#conn.commit();
#print("insert student 1 into table student")

#select from student
cursor = conn.execute("select id, name, age, address from student")

for row in cursor:
    print("ID = %d, name = %s, address=%s, age=%d" % (row[0], row[1], row[3], row[2]))


conn.close();
