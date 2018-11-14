#!/usr/bin/python
import re


s = '<head><meta charset=gb18030></head>'
r = re.search("<meta charset=([\w-]*)>", s, re.IGNORECASE)

print("result:")
print(r.group(1))
exit()

s = 'AutoPtr<IInterface> (*elastos_AndroidProtocolHandler_open)(IInterface* context, const Elastos::String& url);'
m = re.match('(.*)[ ]{1,}\(\*(.*)\)\((.*)\);', s)
print m
print(m.groups())

reStr = r'.*\.(htm|html)$'
pattern = re.compile(reStr)
testStr = ["http://www.baidu.com", "http://www.baidu.com/index.html", "http://www.baidu.com/default.htm", 'http://www.baidu.com/index.asp', 'http://www.baidu.com/default.jsp',
           "http://www.baidu.com/indexahtml",
]
for s in testStr:
    m = pattern.match(s)
    if m:
#print(m.groups())
        print(m.group())


