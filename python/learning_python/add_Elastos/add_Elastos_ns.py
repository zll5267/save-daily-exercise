#!/usr/bin/python
'''
Because the ArrayOf, Int32/64, Float, Double, Boolean, Handle32, AutoPtr
now under the namespace Elastos,
so we should add Elastos:: before these type used place.
'''
import sys
import os
import optparse
import re

namespace = "Elastos"
file_only_with_suffix = [".h", ".cpp", ".cc"]
type_need_namespace = ['AutoPtr', 'Int32', 'Int64', 'Boolean', 'Float', 'Double', 'ArrayOf', 'Handle32', 'Byte', 'Char16', 'Char32']
#type_need_namespace = ['Byte', 'Char16', 'Char32']

def file_with_suffix(filename, suffixs):
    index = filename.rfind('.')
    suffix = filename[index:]
#print("%s with suffix %s" % (filename, suffix))
    if suffix in suffixs:
        return True
    else:
        return False


def get_file_with_suffix(path, suffixs):
    if os.path.isdir(path):
        for filename in os.listdir(path):
            filename = os.path.join(path, filename)
            for sub_filename in get_file_with_suffix(filename, suffixs):
                yield sub_filename
    else:
        if file_with_suffix(path, suffixs):
#print("%s is the file will be handled" % path)
            yield path

def replace_line(line, types):
    for eltype in types:
        line = line.replace("Elastos::" + eltype, eltype)
    for eltype in types:
#        print("in %s, %s will be update" % (line[:-1], eltype))
        typematch = re.compile('(?P<prefix>[\W]|^)' + eltype + '(?P<suffix>[\W])')
#typematch = re.compile('(?P<prefix>^)' + eltype + '(?P<suffix>[\W])')#only for the type at the beginning of the line
        line, num = typematch.subn(r'\g<prefix>Elastos::' + eltype + r'\g<suffix>', line)
    return line

def add_namespace(path, namespace, types, suffixs):
    '''
    add @namespace for the @types in files with the @suffix under @path dir
    e.g. Int32 -> Elastos::Int32
    '''
    for filename in get_file_with_suffix(path, suffixs):
#       print(filename)
        #don't update the _dec.h file, which provide for the framework layer usage
        if filename.endswith("_dec.h"):
            continue
        #don't conside the test files
        if (filename.endswith("_unittest.cc")) or (filename.find(r'/test/') != -1):
            continue
        with open(filename) as fi:
            with open(filename + 'bak', 'w') as fo:
                for line in fi:
                    #only handle the not comment line, no consider the comment style/* */
                    if not line.lstrip().startswith("//"):
                        line = replace_line(line, types)
                    fo.write(line)
        os.remove(filename)
        os.rename(filename + 'bak', filename)

def main(argv):
    print("enter main with argv:" + str(argv))
    usage = "this tool used to add the namespace Elastos for the types, e.g. AutoPtr,Int32"
    op = optparse.OptionParser(usage)
    op.add_option("-p", "--path", dest="path", help="the dir which will be handled")
    options, argv = op.parse_args(argv);

    if not options:
        print("the path is NULL, please indicate the path will be handled")
    else:
        path = options.path
        if (not path) or (not os.path.exists(path)):
            print("the path is invalid, please indicate the path will be handled")
        else:
            path = os.path.abspath(path)
            print("the dir will be handled is:" + path)
            add_namespace(path, namespace, type_need_namespace, file_only_with_suffix)

if __name__ == "__main__":
    sys.exit(main(sys.argv))

