#!/usr/bin/python3
import classtools

class Person(classtools.AttrDisplay):
    def __init__(self, name, job=None, pay=0):
        self.name = name
        self.job = job
        self.pay = pay

    def lastName(self):
        return self.name.split()[-1]
    def giveRaise(self, percent):
        self.pay = int(self.pay * (1 + percent))

class Manager(Person):
    def __init__(self, name, pay):
        Person.__init__(self, name, 'mgr', pay)
    def giveRaise(self, percent, bonus=.10):
        Person.giveRaise(self, percent + bonus)

if __name__ == "__main__":
    #self test code
    bob = Person('Bob Smith')
    sue = Person('Sue Jones', job='dev', pay=10000)
    print(bob.name, bob.pay)
    print(sue.name,sue.pay,sue.job)
    print(bob.lastName(), sue.lastName())
    sue.giveRaise(.1)
    print(sue.pay)
    print(bob)
    print(sue)
    tom = Manager('Tom Jones', 50000)
    tom.giveRaise(.10)
    print(tom.lastName())
    print(tom)
    print('--All three --')
    for obj in (bob, sue, tom):
        obj.giveRaise(.10)
        print(obj)
