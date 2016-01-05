#!/usr/bin/env python
import pika

connection = pika.BlockingConnection(pika.ConnectionParameters('localhost'))
channel = connection.channel()

channel.exchange_declare(exchange='logs', type='fanout')#broadcast to all the binded queues
channel.exchange_declare(exchange='boulder', type='fanout')#broadcast to all the binded queues

result = channel.queue_declare(exclusive=True)#random name picked by rabbitmq, delete when disconnect
queuename = result.method.queue
print("queue name:" + queuename)
channel.queue_bind(exchange='logs', queue=queuename)

print(' [*] Waiting for logs. To exit press CTRL+C')
def callback(ch, method, properties, body):
    print(" [x] %r" % body)


channel.basic_consume(callback,
                      queue=queuename,
                      no_ack=True)

channel.start_consuming()
