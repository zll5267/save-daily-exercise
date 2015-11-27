#!/usr/bin/python
import sys

def main(argv):
    print "enter main"
    while True:
        s = raw_input("please input a num:")
        if s == "stop": break
        try:
            n = int(s)
        except:
            print "BAD!" * 4
        else:
            print n ** 2
    print "Bye!!!"
if __name__ == "__main__":
    sys.exit(main(sys.argv))
