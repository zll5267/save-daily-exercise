#!/usr/bin/python
import sys

def main(argv):
    print "enter in main"
    while True:
        s = raw_input("please input a num:")
        if s == "stop":
            break;
        elif not s.isdigit():
            print("BAD!" * 3)
        else:
            print(int(s) ** 2)
    print "Bye!"

if __name__ == "__main__":
    sys.exit(main(sys.argv))

