CC = gcc
CFLAGS = -Wall -g

guiao1: guiao1.o person.o exercicios.o

person.o: person.c person.h

exercicios.o: exercicios.c exercicios.h

guiao1.o: guiao1.c exercicios.h

clean:
	rm -f *.o guiao1 pessoas file_pessoas

