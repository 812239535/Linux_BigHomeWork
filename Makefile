main:main.o Queue.o Stack.o Tree.o 
	gcc main.o Queue.o Stack.o Tree.o -o main
main.o:main.c
	gcc -c main.c
Queue.o:Queue.c
	gcc -c Queue.c
Stack.o:Stack.c
	gcc -c Stack.c
Tree.o:Tree.c
	gcc -c Tree.c

clean:
	rm main *.o
