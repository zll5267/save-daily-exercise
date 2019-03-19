SHARE_LIB_FILES = share_lib.c

lib:
	gcc -fPIC --shared -o libshared.so $(SHARE_LIB_FILES)
objdump:
	objdump -SD libshared.so > libshared.dump
