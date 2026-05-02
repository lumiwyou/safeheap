SRCS = $(wildcard core/*.c) $(wildcard core/**/*.c) $(wildcard core/**/**/*.c)
OBJS = $(SRCS:.c=.o)

test: build/test

documentation: build/documentation

build/test: tests/test.c $(OBJS)
	gcc -g -I. tests/test.c $(OBJS) -o build/test
	./build/test

build/documentation:
	doxygen Doxyfile

clean:
	rm -f build/test
	rm -f $(OBJS)
	rm -rf build/doxygen

all: clean test documentation