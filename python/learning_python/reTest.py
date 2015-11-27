#!/usr/bin/python
import re

s = 'AutoPtr<IInterface> (*elastos_AndroidProtocolHandler_open)(IInterface* context, const Elastos::String& url);'
m = re.match('(.*)[ ]{1,}\(\*(.*)\)\((.*)\);', s)
print m
print(m.groups())
