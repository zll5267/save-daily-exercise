#!/usr/bin/python3

import sys
import os
import optparse

def is_free_line(line):
    if line.find("duer_free_ext") != -1:
        addr_begin_index = line.find("addr =")
        if addr_begin_index != -1:
            return line[addr_begin_index + 7:]
        return None
    else:
        return None

def is_malloc_line(line):
    if line.find("duer_malloc_ext") != -1:
        addr_begin_index = line.find("addr =")
        if addr_begin_index != -1:
            addr_end_index = line.find(",", addr_begin_index)
            return line[addr_begin_index + 7:addr_end_index]
        return None
    else:
        return None

def leak_line(input_file, line, start_line):
    malloc_line = is_malloc_line(line)
    if malloc_line and len(malloc_line) > 0:
        malloc_line = malloc_line.strip("\n")
        line_num = 0
        with open(input_file) as finput:
            for line in finput:
                line_num += 1
                if (line_num <= start_line):
                    continue
                else:
                    free_line = is_free_line(line)
                    if free_line:
                        free_line = free_line.strip("\n")
                        if free_line == malloc_line:
                            return None
        return line
    else:
        return None

def checkMemoryLeak(input_file, output_file):
    line_num = 0
    with open(input_file) as finput:
        for line in finput:
            line_num += 1
            if leak_line(input_file, line, line_num):
                print(str(line_num) + ":" + line);
def test_main():
    test_line = is_free_line("[I]{tid:20851}().c(212):duer_free_ext: file:, line:388, addr = 20002760");
    if test_line:
        print("line:" + test_line + ";")
#test_line = is_malloc_line("[I]{tid:20851}().c(194):duer_malloc_ext: file:, line:5375, addr = 20003c80, size = 2365");
    test_line = is_malloc_line("[I]{tid:20851}().c(194):duer_malloc_ext: file:, line:5375, ");
    if test_line:
        print("line:" + test_line + ";" + str(len(test_line)))

    s1 = "20002920"
    s2 = "20002920"
    if s1 == s2:
        print("s1 == s2")

def main(argv):
    print( "enter main ...")
#print "argv:" + str(argv)
    usage = "how to use this tool"
    op = optparse.OptionParser(usage=usage);
    op.add_option('-s', '--source', dest="input_file",
            help="the log got from the device using the debug version of memory alloc/free, more info see lightduer_memory.h DUER_MEMORY_DEBUG");
    op.add_option('-t', '--target', dest="output_file", help="the output file");
    o,a = op.parse_args(argv)

    input_file = o.input_file
    output_file = o.output_file
    if (not input_file) or (not os.path.exists(input_file)):
        print("please input the input file");
        sys.exit(0)
    else:
        print("input file: " + input_file)

#    if (not output_file):
#        output_file = "output.txt"
#    print("output file: " + output_file)

    checkMemoryLeak(input_file, output_file)
#test_main()

if __name__ == "__main__":
    sys.exit(main(sys.argv))
