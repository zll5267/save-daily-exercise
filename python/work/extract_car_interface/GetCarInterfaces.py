#!/usr/bin/python3

import sys
import os
import optparse
import re


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

#return ["Elastos::Droid::Internal::Policy::Impl"]
def getInterfacesFromCarFile(fcar):
    nsStart = False
    ifStart = False
    namespace = ""
    interfaces = []
    result = []
    for line in fcar:
        if line.find("namespace") != -1:
#print("nnn:" + line)
            nsMatch = re.compile("[\s\W{;.]*namespace[\s]+(?P<ns>[\w]+)[\s]*{[\s]*")
            am = nsMatch.findall(line)
            if len(am) > 0:
                #maybe one car file declare more than one interface in different namespaces
                #here means a new namespace start
                #the new namespace must start with full name-path
                if ifStart:
                    result += [namespace + "::" +item for item in interfaces]
                    interfaces = []
                    namespace = ""
                    ifStart  = False
                if not nsStart:
                    nsStart = True
                for m in am:
                    if m:
                        if namespace:
                            namespace += "::"
                        namespace += m
        if nsStart:
            if line.find("interface") != -1:
#print("iiiii" + line)
                ifMatch = re.compile("[\s]*interface[\s]+(?P<if>I[\w]+)[\s]*{[\s]*")
                am = ifMatch.findall(line)
                for m in am:
                    if m:
                        if not ifStart:
                            ifStart = True
                        interfaces.append(m)

#print("ns:" + namespace)
#print("interfaces:" + str(interfaces))
    result += [namespace + "::" +item for item in interfaces]
    return result

def handleInterfaces(interfaces):
#print(interfaces)
    for interface in interfaces:
        print(interface)

def getInterfaces(carfile):
    suffixs = [".car"]
    interfaces = []
    for filename in get_file_with_suffix(carfile, suffixs):
        with open(filename) as fcar:
            interfaces += getInterfacesFromCarFile(fcar)
    handleInterfaces(interfaces)

def main(argv):
    debug = True
    #print( "enter main ...")
    #print "argv:" + str(argv)
    usage = "how to use this tool"
    op = optparse.OptionParser(usage=usage);
    op.add_option('-c', '--carfile', dest="carfile", help="the carfile/or car file path used to extract the declared interface");
    o,a = op.parse_args(argv)

    carfile = o.carfile
    if (not carfile) or (not os.path.exists(carfile)):
        print("please input the car file or directory contains car file");
        sys.exit(0)
    else:
        pass
        #print("car file/path: " + carfile)

    getInterfaces(carfile)

if __name__ == "__main__":
    sys.exit(main(sys.argv))
