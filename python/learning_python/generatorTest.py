#!/usr/bin/python

import sys
def lprint(n):
    while True:
        n = yield n **2
def main(argv):
    print("enter main ...")
    o = lprint(0)
    o.send(None)
    while True:
        try:
            readStr = raw_input("input a number(stop exit):")
            if readStr == "stop":
                break;
            n = int(readStr)
        except:
            print("only number accepted")
        else:
            print(o.send(n))


if __name__ == "__main__":
    sys.exit(main(sys.argv))
