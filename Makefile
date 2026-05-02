SRCS = $(wildcard core/*.c) $(wildcard core/**/*.c) $(wildcard core/**/**/*.c)
OBJS = $(SRCS:.c=.o)

test: build/test

build/test: tests/test.c $(OBJS)
	gcc -g -I. tests/test.c $(OBJS) -o build/test
	./build/test

clean:
	rm -f build/test
	rm -f $(OBJS)

all: clean test