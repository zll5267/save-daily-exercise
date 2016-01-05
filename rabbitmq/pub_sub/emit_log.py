#!/usr/bin/env python
import sys
import pika

connection = pika.BlockingConnection(pika.ConnectionParameters('localhost'))
channel = connection.channel()

channel.exchange_declare(exchange='logs', type='fanout')#broadcast to all the binded queues

#result = channel.queue_declare(exclusive=True)#random name picked by rabbitmq, delete when disconnect
#print("queue name:" + result.method.queue)
#channel.queue_bind(exchange='logs', queue=result.method.queue)

message=' '.join(sys.argv[1:]) or "info: Hello World!"
channel.basic_publish(exchange='logs',
                      routing_key='',
                      body=message)

print(" [x] Send '%r!'" % message)
connection.close()
