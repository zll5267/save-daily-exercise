#!/usr/bin/env python
import sys
import pdb


def get_next_array(string):
    '''
        @param: string used to get the partial match table
        @return list of partial match table for @string
    '''
    pdb.set_trace()
    next = [0] * len(string)
    j = next[0] #next[i-1]
    for i in range(len(string))[1:]:
        while(j > 0 and string[i] != string[j]):
            j = next[j]
        if string[i] == string[j]:
            j += 1
        next[i] = j
    return next

def main(argv):
    if (len(argv) != 2 ):
        print("Usage: %s string" % argv[0])
        exit(0)
    print("enter main with arguments:" + str(argv[1:]))
    result = get_next_array(argv[1])
    print(result)

if __name__ == "__main__":
    sys.exit(main(sys.argv))

