import urllib
url1 = "http://www.baidu.com"
url2 = "http://www.baidu.com:8080/index.html"
filename1 = urllib.quote(url1, '')
print("convert %s to %s" % (url1, filename1))
print("unconvert %s to %s" % (filename1, urllib.unquote(filename1)))
filename2 = urllib.quote(url2, '')
print("convert %s to %s" % (url2, filename2))
print("convert %s to %s" % (url2, filename2))
