https://my.oschina.net/u/180497/blog/177206

ld --verbose  //get the default link script *.lds

before '__bss_start = .;' add:
_myown_start = .;
.myown : { *(.myown) };
_myown_send = .;

----------------
extern type _myown_start;
extern type _myown_end;

static type var1 __attribute__((unused, section(".myown"))) = xxx1;
static type var2 __attribute__((unused, section(".myown"))) = xxx2;
-------------------------

gcc xx.c -Wl,-Town.lds
gcc main.c test.c -o test -Wl,-Tmyown.lds
