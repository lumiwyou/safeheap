test:
	gcc -g -I. tests/test.c -o build/test
	./build/test

clean:
	rm -f build/test

all: clean test