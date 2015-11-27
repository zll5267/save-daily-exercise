#!/usr/bin/python
import sys
import random

def get_data():
    return random.sample(range(10), 3)

def consume():
    data_sum = 0
    data_count = 0
    while True:
        data = yield
        data_count += len(data)
        data_sum += sum(data)
        print("all data avarage is {}".format(data_sum/float(data_count)))

def produce(consumer):
    while True:
        data = get_data()
        print("produced {}".format(data))
        consumer.send(data)
        yield

def main(argv):
    print("enter main ...")
    consumer = consume()
    consumer.send(None)
    producer = produce(consumer)

    for _ in range(10):
        print("producing ...")
        next(producer)

if __name__ == "__main__":
    sys.exit(main(sys.argv))
