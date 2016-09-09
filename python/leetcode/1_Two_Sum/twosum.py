#!/usr/bin/env python

initArray = [1, 2, 3, 10, 20, 30]
strInitArray=str(initArray)
import argparse

parser = argparse.ArgumentParser(description="get the two values from "
                                    + strInitArray
                                    + "\nwhich add up with the value num")

parser.add_argument("num", help="the sum value")
args = parser.parse_args()

print "the sum value you want is: " + args.num


