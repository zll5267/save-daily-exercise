#!/usr/bin/env python
# *(star) can substitute for exactly one word
# #(hash) can substitute for zero or more words
import pika
import sys

connection = pika.BlockingConnection(pika.ConnectionParameters(host='localhost'))
channel = connection.channel()

channel.exchange_declare(exchange='topic_logs', type='topic')
routing_key = sys.argv[1] if len(sys.argv) > 1 else 'annonymous.info'
message = ' '.join(sys.argv[2:]) or 'Hello World!'

channel.basic_publish(exchange='topic_logs', routing_key=routing_key, body=message)

print(" [x] Send %r:%r" % (routing_key, message))
connection.close()

