import threading, time

def test_run():
    print("%s thread is running, time:%f" % (threading.current_thread().name, time.time()))

def start_test():
    threads = []
    for i in range(5):
        t = threading.Thread(target=test_run)
        t.start()
        threads.append(t)

    for t in threads:
        t.join()

if __name__ == '__main__':
    print(threading.current_thread().name)
    print(time.time())
    test_run()
    start_test()

