#!/usr/bin/python3

import sys
import os
import optparse
import re

g_all_declared_interfaces_list = [
    "Elastos::Droid::Internal::Policy::Impl::Keyguard::CKeyguardExitDelegate",
    "Elastos::Droid::Internal::Policy::Impl::Keyguard::CKeyguardShowDelegate",
        ]
g_all_declared_interfaces_dic = {}

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
#print("nnn" + line)
            if not nsStart:
                nsStart = True
            nsMatch = re.compile("[\s\W]*namespace[\s]+(?P<ns>[\w]*)[\s]*{[\s]*")
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
            for m in am:
                if m:
                    if namespace:
                        namespace += "::"
                    namespace += m
        if nsStart:
            if line.find("interface") != -1:
#print("iiiii" + line)
                ifStart = True
                ifMatch = re.compile("[\s]*interface[\s]+(?P<if>[\w]+)[\s]*{[\s]*")
                am = ifMatch.findall(line)
                for m in am:
                    if m:
                        interfaces.append(m)

#print("ns:" + namespace)
#print("interfaces:" + str(interfaces))
    result += [namespace + "::" +item for item in interfaces]
    return result

def handleInterfaces(interfaces):
    for interface in interfaces:
        print(interface)

def getInterfaces(carfile):
    suffixs = [".car"]
    interfaces = []
    for filename in get_file_with_suffix(carfile, suffixs):
        with open(filename) as fcar:
            interfaces += getInterfacesFromCarFile(fcar)
#handleInterfaces(interfaces)
    return interfaces

def handleNeededInterfaces(filename, needed_interfaces):
    global g_all_declared_interfaces_dic
    #print(g_all_declared_interfaces_dic)
    print(filename + "needed interfaces:")
    #the interface source will be len(interface_startwords) + 1(other)
    interface_startwords = {"Elastos::Droid":[], "Elastos::Core":[], "other":[]}
    for interface in needed_interfaces:
        interface_with_ns = g_all_declared_interfaces_dic.get(interface, interface)
        if interface_with_ns == interface:
            if (interface.startswith("C")):
                interface_with_ns = g_all_declared_interfaces_dic.get("I" + interface[1:], interface)
                if interface_with_ns != interface:
                    interface_with_ns = interface_with_ns[:interface_with_ns.rfind(":")] + interface;
        interface = interface_with_ns
        for startwords in interface_startwords:
            if interface.startswith(startwords):
                interface_startwords[startwords].append(interface)
                break
        else:
            interface_startwords["other"].append(interface)
    for startwords in interface_startwords:
        print("=========interface for :" + startwords + "================")
        interfaces = sorted(interface_startwords[startwords])
        for interface in interfaces:
            print("using " + interface + ";")


def getNeededInterfacesForFile(f):
    needed_interfaces = set()
    not_interfaces = {'Int32', 'Int64', 'IInterface'}#TODO add all the not interfaces
    for line in f:
        interfaceMatch = re.compile("[\W](I[\w]+)[\s]*\*")
        find_result = interfaceMatch.findall(line)
        interfaceMatch = re.compile("AutoPtr<[\s]*(I[\w]+)[\s]*>")
        find_result += interfaceMatch.findall(line)
        interfaceMatch = re.compile("(C[\w]+)::New")
        find_result += interfaceMatch.findall(line)
        if len(find_result) > 0:
            for i in find_result:
                if i:
                    needed_interfaces.add(i)
    return needed_interfaces - not_interfaces

def getNeededInterfacesForDir(path):
    suffixs = [".h", ".cpp"]
    for filename in get_file_with_suffix(path, suffixs):
        needed_interfaces = set
        with open(filename) as fc:
            needed_interfaces = getNeededInterfacesForFile(fc)
            handleNeededInterfaces(filename, needed_interfaces)

def fileExist(f):
    if (not f) or (not os.path.exists(f)):
        print("please check if the '%s' exists!!!!", f);
        sys.exit(0)
    else:
        print("input file/path: " + f)

def filesExist(files):
    '''files is a list of files'''
    for f in files:
       fileExist(f)

def main(argv):
    debug = True
    print( "enter main ...")
    #print "argv:" + str(argv)
    usage = "how to use this tool"
    op = optparse.OptionParser(usage=usage);
    #when -i exist then -c parameter will not have any effect
    op.add_option('-f', '--file', dest="inputfile", help="the c++ .h/.cpp files or path used to get the using interface");
    op.add_option('-c', '--carfile', dest="carfile", help="the car files or car file path used to get the exist interfaces");
    op.add_option('-i', '--interfacefile', dest="interfacefile", help="the file which contains all the declared interfaces");
    o,a = op.parse_args(argv)
    if debug:
#o.inputfile = "/home/leliang/work/ElastosRDK5/ElastosRDK5_0/Sources/Elastos/Frameworks/Droid/Base/Core/src/elastos/droid/internal/policy/impl/keyguard/KeyguardServiceDelegate.cpp"
        o.inputfile = "/home/leliang/work/ElastosRDK5/ElastosRDK5_0/Sources/Elastos/Frameworks/Droid/Base/Core/src/elastos/droid/view/View.cpp"
        o.interfacefile = "/home/leliang/myfile/projects/save-daily-exercise/python/work/extract_car_interface/interfaces.txt"
        o.carfile = "/home/leliang/work/ElastosRDK5/ElastosRDK5_0/Sources/Elastos/LibCore/car/elastosx/sql/IRowSetReader.car"
    #
    all_needed_interfaces = set
    #maybe multiple files/paths with ';' separator
    #inputfile and carfile are the arguments
    interfacefile = o.interfacefile
    global g_all_declared_interfaces_dic
    global g_all_declared_interfaces_list
    if interfacefile:
        fileExist(interfacefile)
        with open(interfacefile) as finterfaces:
            g_all_declared_interfaces_list += finterfaces.readlines();
            g_all_declared_interfaces_list = [line.strip('\n') for line in g_all_declared_interfaces_list]
            g_all_declared_interfaces_dic = {name[name.rfind(':')+1:]: name for name in g_all_declared_interfaces_list}
            #print((g_all_declared_interfaces_dic))
    else:
        carfile = o.carfile
        carfiles = carfile.split(";")
        filesExist(carfiles)
        for f in carfiles:
            g_all_declared_interfaces_list += getInterfaces(f)
            g_all_declared_interfaces_dic = {name[name.rfind(':')+1:]: name for name in g_all_declared_interfaces_list}
    inputfile = o.inputfile
    inputfiles = inputfile.split(";")
    filesExist(inputfiles)
    for f in inputfiles:
        getNeededInterfacesForDir(f)


if __name__ == "__main__":
    sys.exit(main(sys.argv))
