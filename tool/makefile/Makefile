CC = gcc
OUTPUT = output/

sources = $(wildcard src/*.c)

objects = $(patsubst %.c,$(OUTPUT)%.o, ${sources})

depends = $(patsubst %.o, %.d, ${objects})

#$(info sources: ${sources})
#$(info objects: ${objects})

all : $(objects) test
.PHONY : all

#vpath %.h include

MY_INCLUDE = include

CFLAGS += -I$(MY_INCLUDE)

$(objects) : ${OUTPUT}%.o : %.c
	[ ! -e $@ ] && mkdir -p $(dir $@); \
	$(CC) -c $(CFLAGS) $< -o $@

$(depends) : $(OUTPUT)%.d: %.c
	[ ! -e $(dir $@) ] && mkdir -p $(dir $@); \
	set -e; rm -f $@; \
	$(CC) -MM -MT $*.o $(CFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,$(OUTPUT)\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

test : $(objects)
	$(CC) -I${MY_INCLUDE} -o $(OUTPUT)$@ $^

.PHONY : clean distclean
clean :
	rm -rf $(objects) $(depends) $(OUTPUT)test

distclean :
	rm -rf $(OUTPUT)

-include $(depends)

