import random
import sqlite3

conn = sqlite3.connect('testDB.db')

cursor = conn.execute('select * from students')

for row in cursor:
    print(row)

cursor = conn.execute('select max(id) from students')
max_id = 1
for row in cursor:
    max_id = row[0]

print('max_id: %d' % max_id)
#id, name, age, score
students_insert_full_string = 'insert into students values(?,?,?,?)'
s_id = max_id + 1
max_id = s_id
s_name = random.choice(['lisi', 'wangwu', 'zhaoliu', 'luqi', 'chenba'])
s_age = random.randint(8,12)
s_score = random.uniform(50.5, 95.5)
s_parameters = (s_id, s_name, s_age, s_score)
conn.execute(students_insert_full_string, s_parameters)
conn.commit()

conn.close()
