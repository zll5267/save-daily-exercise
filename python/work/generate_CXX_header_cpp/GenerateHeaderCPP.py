#!/usr/bin/python3

import sys

def main(argv):
    if len(argv) < 3:
        print("usage: %s namespace className " % argv[0])
        print("e.g.:  %s Elastos.Droid.Internal.Policy.Impl.Keyguard KeyguardExitDelegate " % argv[0])
        sys.exit()
    else:
        print("generate header and cpp for class %s, " % argv[2])
        print("namespace is %s " % argv[1])
    namespace = argv[1].split(".")
    className = argv[2]
    CclassName = "C" + className
    #print(namespace)
    header_include_control_macro = "__"
    auto_generated_header_file_for_carclass = "_"
    filepath = ""
    for ns in namespace:
        header_include_control_macro += ns.upper() + "_"
        auto_generated_header_file_for_carclass += ns + "_"
        filepath += ns.lower() + "/"
    header_include_control_macro += CclassName.upper() + "_H__"
    auto_generated_header_file_for_carclass += CclassName + ".h"
    pure_cpp_class_header_file = filepath + className + ".h"
    Car_cpp_class_header_file = filepath + CclassName + ".h"
    #print("header_include_control_macro:" + header_include_control_macro)
    #generate the CXX.h
    CxxhFile = CclassName + ".h"
    with open(CxxhFile, "w") as cxxh:
        cxxh.write("#ifndef " + header_include_control_macro + "\n")
        cxxh.write("#define " + header_include_control_macro + "\n")
        cxxh.write("\n")
        cxxh.write("#include \"" + auto_generated_header_file_for_carclass + "\"\n")
        cxxh.write("//#include \"" + pure_cpp_class_header_file + "\"\n")
        cxxh.write("\n")
        for ns in namespace:
            cxxh.write("namespace " + ns + " {\n")
        cxxh.write("\n")
        cxxh.write("CarClass(" + CclassName + ")\n")
        cxxh.write("    //, public " + className + "\n")
        cxxh.write("{\n")
        cxxh.write("public:\n")
        cxxh.write("    CAR_OBJECT_DECL()\n")
        cxxh.write("};\n")
        cxxh.write("\n")
        namespace.reverse()
        for ns in namespace:
            cxxh.write("} // namespace " + ns + "\n")
        namespace.reverse()
        cxxh.write("\n")
        cxxh.write("#endif // " + header_include_control_macro + "\n")

    CxxcppFile = CclassName + ".cpp"
    with open(CxxcppFile, "w") as cxxcpp:
        cxxcpp.write("#include \"" + Car_cpp_class_header_file + "\"\n")
        cxxcpp.write("\n")
        for ns in namespace:
            cxxcpp.write("namespace " + ns + " {\n")
        cxxcpp.write("\n")
        cxxcpp.write("CAR_OBJECT_IMPL(" + CclassName + ")\n")
        cxxcpp.write("\n")
        namespace.reverse()
        for ns in namespace:
            cxxcpp.write("} // namespace " + ns + "\n")
        namespace.reverse()


if __name__ == "__main__":
    sys.exit(main(sys.argv))

