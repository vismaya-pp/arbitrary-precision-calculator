output.exe : main.o add.o sub.o mul.o div.o disp.o list.o util.o
	gcc -o output.exe main.o add.o sub.o mul.o div.o disp.o list.o util.o

main.o : main.c apc.h
	gcc -c main.c

add.o : add.c apc.h
	gcc -c add.c

sub.o : sub.c apc.h
	gcc -c sub.c

mul.o : mul.c apc.h
	gcc -c mul.c

div.o : div.c apc.h
	gcc -c div.c

disp.o : disp.c apc.h
	gcc -c disp.c

list.o : list.c apc.h
	gcc -c list.c

util.o : util.c apc.h
	gcc -c util.c

clean :
	rm -f *.o *.exe