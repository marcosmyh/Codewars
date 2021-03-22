MAKEFLAGS += --silent
CC = gcc
LIBS = -lcspecs
CFLAGS = -g -Wall

SOURCES := $(shell find ./ -name \*.c)
SOURCE_DIRS := $(dir $(SOURCES))
TARGETS := $(filter-out Unit_tests,$(basename $(notdir $(SOURCES))))

all: $(TARGETS)

.SECONDEXPANSION:
$(TARGETS): % : %/$$*.o %/Unit_tests.o
	$(CC) $(CFLAGS) $(LIBS) -o $@/Tests $^

SOURCE_DIRS/%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	$(foreach target,$(TARGETS),cd $(target) && rm -f *.o Tests && cd ..;)