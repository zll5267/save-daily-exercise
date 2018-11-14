
def test_str():
    str0 = 'javascript:location.href="page4.html"'

    p = str0.find("href=")
    str1 = str0[p+5:]
    print(str1)
    str2 = str1.strip("'").strip('"')
    print(str2)

    o_url = "http://www.baidu.com/index.html"
#o_url = "http://www.baidu.com"
    last_slash = o_url.rfind("/")
    if o_url[last_slash-1] != '/' and o_url[last_slash-2] != ':':
        print(o_url[0:last_slash])
    else:
        print(o_url)

def str_con():
    str1 = "Hello"
    str2 = "World"
    str3 = "you"
    l = [str1, str2, str3]
    print(' '.join(l))
if __name__ == '__main__':
#test_str()
    str_con()
