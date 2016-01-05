#!/usr/bin/env python
import pika

def callback(ch, method, properties, body):
    print(" [x] received %r" % body)

connection = pika.BlockingConnection(pika.ConnectionParameters('localhost'))
channel = connection.channel()

channel.queue_declare(queue='hello')
channel.basic_consume(callback, queue='hello', no_ack=True)

print(' [*] waiting for messages. To exit press CTRL+C')
channel.start_consuming()
