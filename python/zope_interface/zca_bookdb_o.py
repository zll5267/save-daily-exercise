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

class FrontDesk(object):
    def book_room(self, name, place):
        next_id = get_next_id()
        bookings_db[next_id] = {
	    'name': name,
	    'place': place
        }


class FrontDesk(object):
    def book_room(self, guest):
        next_id = get_next_id()
        bookings_db[next_id] = {
	    'name': guest.name,
	    'place': guest.place
	    'phone': guest.phone
        }




