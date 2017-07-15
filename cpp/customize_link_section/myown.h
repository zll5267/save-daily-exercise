#ifndef MYOWN_H__
#define MYOWN_H__

typedef void (*myown_call)(void** state);

#define _myown_init __attribute__((unused, section(".myown")))
#define myown_func_init(func) myown_call _myown_fn_##func _myown_init = func

#endif // MYOWN_H__
