#!/usr/bin/python3
#https://www.python.org/dev/peps/pep-0420/
import sys
import pkg_resources

sys.path = ['lib/test/namespace_pkgs/project1', 'lib/test/namespace_pkgs/project2']

#pkg_resources.declare_namespace("parent")

print(parent.__path__)

import parent.child.one

print(parent.__path__)
print(parent.child.__path__)

import parent.child.two
