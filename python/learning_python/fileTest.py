#!/usr/bin/python
import sys
import os
import optparse

def main(argv):
    print "enter main ..."
    print "argv:" + str(argv)
    usage = "how to use this tool"
    op = optparse.OptionParser(usage=usage);
    op.add_option('-i', '--input', dest="input", help="the input file");
    op.add_option('-o', '--output', dest="output", help="the output file");
    o,a = op.parse_args(argv)
    print "parsed option:" + str(o) + "; type of o is:" + str(type(o))
    print "remain option:" + str(a) + "; type of a is:" + str(type(a))

    ofilepath = o.output
    ifilepath = o.input
    print "input file:" + ifilepath
    print "output file:" + ofilepath

    if ifilepath and os.path.exists(ifilepath):
        ifilepath = os.path.abspath(ifilepath);
        print "abspath of input file:" + ifilepath
    else:
        print "input file does not exists"
    for line in open(ifilepath):
        print line.strip('\n')
if __name__ == "__main__":
    sys.exit(main(sys.argv))
