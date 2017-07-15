#!/usr/bin/env bash

#DEBUG=1

function usage() {
    echo "usage $0:"
    echo "$0 [-l n] [-p prefix] file"
    echo "  -l: indicate how many base directory will be use;"
    echo "      e.g. -l 2, means a/b/c/file.h, will get b and c in the include guard"
    echo "      B_C_FILE_H"
    echo "  -p: set a fixed prefix"
    echo "      e.g. l 1 -p PREFIX_XXX means file a/b/c/file.h will use include guard"
    echo "      PREFIX_XXX_C_FILE_H"
    echo "  file: the file will add the include guard"
    echo "note:"
    echo "     set evn Author_lastName_ll&Author_firstName_ll&EmailName_ll "
    echo "     first as the author and email username"
}

function debug() {
    if [ $DEBUG ]; then
       echo $1
    fi
}

# return 0 when input $1 is integer or return 1
function isIntNum() {
    if [ $# -lt 1 ]; then
        return 1;
    fi
    if [[ $1 =~ ^-?[1-9][0-9]*$ ]]; then
        return 0;
    fi
    if [[ $1 =~ ^0$ ]]; then
        return 0;
    fi

    return 1;
}

function notempty() {
    [ "x${1}" != "x" ]
}

# $1 provide the default vlaue first, and as an output var
# $2 prompt
# $3 validate function
function input() {
    var="${1}"
    prompt="${2}"
    validate="${3:-notempty}"
    defValue=`eval echo \\$$var`
    tmp=""
    until eval ${validate} "${tmp}"
    do
        if [ "x${defValue}" = "x" ]; then
            echo "${prompt}:"
        else
            echo "${prompt}[$defValue]:"
        fi
        read tmp
        test "x${tmp}" = "x" && tmp="${defValue}"
    done
    eval "$var=$tmp"
}

debug "argument num is:$#"
if [ $# -lt 1 ]; then
    usage;
    exit;
fi

if [ $1 == "-l" ]; then
    debug "arg 2 is:$2"
    shift
    if ! eval isIntNum $1
    then
        usage ; exit;
    fi
    LEVEL=$1
    shift
fi

if [ $1 == "-p" ]; then
    debug "arg 2 is:$2"
    shift
    PREFIX=$1
    shift
fi

debug "file:$1;"
if [ -z $1 ]; then
    echo "no input file!!!!"
    usage
    exit
fi
if [ ! -f $1 ]; then
    echo "file $1 does not exist or is not a normal file!!!!!!"
    usage
    exit
fi
FILE=$1
debug "FILE:$FILE;LEVEL:$LEVEL;prefix:$PREFIX"
filePath=`readlink -f $FILE`
fileName=`basename $filePath`
dirPath=`dirname $filePath`
echo "fileName:$fileName"
echo "dirPath:$dirPath"

if [ "x$LEVEL" = "x" ]; then
    LEVEL=6 #default value
    input LEVEL "please input the LEVEL" isIntNum
fi

while [ $LEVEL -gt 0 ]; do
    debug "level:$LEVEL"
    INCLUDE_GUARD="${dirPath##*/}_${INCLUDE_GUARD}"
    dirPath=${dirPath%/*}
    ((--LEVEL))
done

#add the fileName, no '_' before the fileName needed, added before
if [ -z $PREFIX ]; then
INCLUDE_GUARD="${INCLUDE_GUARD}${fileName}"
else
INCLUDE_GUARD="${PREFIX}_${INCLUDE_GUARD}${fileName}"
fi

#replace . - to _
INCLUDE_GUARD="${INCLUDE_GUARD//./_}"
INCLUDE_GUARD="${INCLUDE_GUARD//-/_}"

#to upper case
INCLUDE_GUARD=`echo ${INCLUDE_GUARD}|tr [a-z] [A-Z]`
debug "INCLUDE_GUARD:$INCLUDE_GUARD"

if [ "x$Author_lastName_ll" = "x" ]; then
    Author_lastName_ll="LastName" #default value
    input Author_lastName_ll "please input the lastName" notempty
fi
if [ "x$Author_firstName_ll" = "x" ]; then
    Author_firstName_ll="FirstName" #default value
    input Author_firstName_ll "please input the firstName" notempty
fi
if [ "x$EmailName_ll" = "x" ]; then
    EmailName_ll="user_name" #default value
    input EmailName_ll "please input the EmailName" notempty
fi

FILE_CLAIM_L1="// Copyright 2017 Baidu Inc. All Rights Reserved.\n"
FILE_CLAIM_L2="// Author: ${Author_lastName_ll} ${Author_firstName_ll} (${EmailName_ll}@baidu.com)\n"
FILE_CLAIM_L3="//\n"
FILE_CLAIM_L4="// Description:\n"
FILE_CLAIM="${FILE_CLAIM_L1}${FILE_CLAIM_L2}${FILE_CLAIM_L3}${FILE_CLAIM_L4}\n"
debug $FILE_CLAIM
sed -i "1i ${FILE_CLAIM}#ifndef $INCLUDE_GUARD\n#define $INCLUDE_GUARD\n" $FILE
#add an empty line
echo "" >> $FILE
echo "#endif // $INCLUDE_GUARD" >> $FILE
