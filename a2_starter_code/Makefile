CC = gcc
CFLAGS = -Wall -std=c99

all: questions qtree

questions:
	$(CC) $(CFLAGS) questions.c test1.c -o test1

qtree:
	$(CC) $(CFLAGS) questions.c qtree.c test2.c -o test2

clean:  
	rm test1
	rm test2