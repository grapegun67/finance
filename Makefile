all: program

program: account.c main.c
	gcc main.c -o program -include account.c

clean:
	rm -rf *.o program exam.txt
