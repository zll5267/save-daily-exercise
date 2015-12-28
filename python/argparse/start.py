import argparse

parser = argparse.ArgumentParser()
parser.add_argument("--verbose", help="increase output verbosity", action="store_true")
parser.add_argument("-l", "--list", help="just for test short options", action="store_true")
parser.add_argument("echo", help="echo the string you use here")
parser.add_argument("square", help="display a square of a given number", type=int)
args = parser.parse_args()
print(args.echo)
print(args.square**2)
if args.verbose:
    print("verbosity turned  on")
import sys
print(__file__)
print(sys._getframe().f_lineno)
