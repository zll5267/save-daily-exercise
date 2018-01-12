
hellos : hello.S
	gcc -c -o hellos.o hello.S
	ld -o hellos hellos.o

.PHONY : clean strace_hellos ltrace_hellos

clean:
	rm -rf hellos.o hellos hello

strace_hellos: hellos
	strace ./hellos

hello : hello.c
	gcc -o hello hello.c

ltrace_hello: hello
	ltrace -S ./hello
