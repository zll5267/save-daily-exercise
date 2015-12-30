#!/usr/bin/python

bookings_db = {}

def get_next_id():
    db_keys = bookings_db.keys()
    if db_keys == []:
        next_id = 1
    else:
        next_id = max(db_keys) + 1
    return next_id

def book_room(name, place):
    next_id = get_next_id()
    bookings_db[next_id] = {
        'name': name,
        'room': place
    }
