#!/usr/bin/python3
#Note depend on the javap command

import sys
import os
import optparse
removeKeyWords = ["abstract "]
def getMethod(line):
    for kw in removeKeyWords:
        line = line.replace(kw, "")
    line = line.strip()
    if line.find("(") != -1 and line.find(")") != -1:# is a method
        #remove the code behind ")", maybe some about exception
        #e.g. public boolean isSecure() throws android.os.RemoteException;
        methodEnd = line.find(")")
        line = line[:methodEnd + 1] + ";"
        return line
    else:
        return None

def getPublicMethodNotDerived(targetPublicMembers, superPublicMembers):
    targetMethodsSet = {"",}
    superMethodsSet = {"",}
    for line in targetPublicMembers.splitlines():
        line = getMethod(line)
        if line:
            targetMethodsSet.add(line)
    for line in superPublicMembers.splitlines():
        line = getMethod(line)
        if line:
            superMethodsSet.add(line)
    print("=================begin public method not derived===============")
    for method in targetMethodsSet - superMethodsSet:
        print(method)
    print("=================end public method not derived===============")

def getPublicMember(targetclass, superclasses):
    targetclass = targetclass.replace(r"$", r"\$")
    targetPublicMembers = os.popen("javap -public " + targetclass).read()
    superclassesPublicMembers = ""
    if superclasses:
        for c in superclasses:
            c = c.replace("$", "\$")
            superclassesPublicMembers += os.popen("javap -public " + c).read()

#print("target public members:\n" + targetPublicMembers)
#print("superclasses public members:\n" + superclassesPublicMembers)
    getPublicMethodNotDerived(targetPublicMembers, superclassesPublicMembers)

def main(argv):
    print( "enter main ...")
#print "argv:" + str(argv)
    usage = "how to use this tool"
    op = optparse.OptionParser(usage=usage);
    op.add_option('-t', '--target', dest="target", help="the target which will use to get the public method");
    op.add_option('-s', '--super', dest="superclasses", help="the super class of class, support multiple, seperated by ;");
    o,a = op.parse_args(argv)

    targetClass = o.target
    superClasses = o.superclasses
    if (not targetClass) or (not os.path.exists(targetClass)):
        print("please input the class file");
        sys.exit(0)
    else:
        print("class file: " + targetClass)
    if superClasses:
        superClasses = superClasses.split(";")
        for c in superClasses:
            if (not c) or (not os.path.exists(c)):
                print("superclass: " + c + " is not exist")
                sys.exit(0)
            else:
                print("superclass: " + c)
    getPublicMember(targetClass, superClasses)

if __name__ == "__main__":
    sys.exit(main(sys.argv))
