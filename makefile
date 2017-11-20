all: pipe.c
	gcc pipe.c

clean:
	rm *~
	rm a.out

run: all
	./a.out
