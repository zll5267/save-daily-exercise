.PHONY : all clean

MY_LIB_PATH = .

all : lib
	gcc -o test test.c -L$(MY_LIB_PATH) -ltest
	gcc -rdynamic -o dltest dltest.c -ldl

lib : testlib.c testlib.h
	gcc -fPIC -shared -o libtest.so $<

clean :
	rm -rf libtest.so test dltest
