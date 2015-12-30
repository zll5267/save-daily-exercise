#!/usr/bin/python
bookings_db = {}

def get_next_id():
    db_keys = bookings_db.keys()
    if db_keys == []:
        next_id = 1
    else:
        next_id = max(db_keys) + 1
    return next_id


from zope.interface import Interface
from zope.interface import Attribute

class IHost(Interface):
    """A host object"""

    name = Attribute("""Name of host""")

    def goodmorning(guest):
        """Say good morning to guest"""

from zope.interface import implements

class Host(object):
    implements(IHost)
    name = 'u'
    def goodmorning(self, guest):
        """Say good morning to guest"""
	return "Good morning, %s!" % guest

host = Host()
print(host.goodmorning("zll"))
print(IHost.providedBy(host))

from zope.interface import invariant

class IDesk(Interface):
    """A frontdesk will register object's details"""
    def register():
        """Register object's details"""

class IGuest(Interface):
    name = Attribute("Name of guest")
    place = Attribute("Place of guest")
    phone = Attribute("Phone of guest")

#marker interface
class ISpecialGuest(Interface):
    """A Special guest"""

from zope.component import adapts

class FrontDeskNG(object):
	implements(IDesk)
	adapts(IGuest)

	def __init__(self, guest):
		self.guest = guest

	def register(self):
		guest = self.guest
		next_id = get_next_id()
		bookings_db[next_id] = {
			'name': guest.name,
			'place': guest.place,
			'phone': guest.phone
		}


class Guest(object):
	implements(IGuest)

	def __init__(self, name, place, phone):
		self.name = name
		self.place = place
		self.phone = phone

jack = Guest('Jack', 'ShangHai', '138xxxxxxxx')

from zope.component import getGlobalSiteManager

gsm = getGlobalSiteManager()

gsm.registerAdapter(FrontDeskNG, (IGuest, ), IDesk, 'ng')

#gsm.registerAdapter(FrontDeskNG, name='ng')

from zope.component import getAdapter
from zope.component import queryAdapter

IGuest.providedBy(host)
ga = getAdapter(host, IDesk, 'ng')
print(ga)

ga = getAdapter(jack, IDesk, 'ng')
print(ga)

