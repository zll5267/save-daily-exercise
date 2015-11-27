#!/usr/bin/python3

import shelve

db = shelve.open('person.db')

for key in sorted(db):
    print(key, '\t=>', db[key])

sue = db['Sue Jones']
sue.giveRaise(.10)
db['Sue Jones'] = sue
db.close()
