TEST = test
DYN = d_test

.PHONY: stat dynam clean start din_start

stat: test

$(TEST): object/func.o object/main.o
	gcc -Wall -o $@ object/main.o object/func.o

object/func.o: src/func.c src/func.h
	mkdir -p object
	gcc -Wall -o $@ -c src/func.c

object/main.o: src/main.c src/func.h
	gcc -Wall -o $@ -c src/main.c

dynam: d_test

$(DYN): object/main.o dynam_object/libfunc.so
	gcc -o d_test object/main.o -L./dynam_object -lfunc -Wl,-rpath,./dynam_object/

dynam_object/libfunc.so: dynam_object/func.o
	gcc -shared -o dynam_object/libfunc.so dynam_object/func.o -ldl
	rm dynam_object/func.o

dynam_object/func.o: src/func.c src/func.h
	mkdir -p dynam_object
	gcc -Wall -fPIC -c src/func.c -o $@

object/main.o: src/main.c src/func.h
	mkdir -p object
	gcc -Wall -o $@ -c src/main.c

clean:
	rm -rf object test dynam_object d_test

start:
	./test

dyn_start:
	LD_LIBRARY_PATH=$PWD ./d_test