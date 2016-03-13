 
CC = gcc
CFLAGS = -I. -c -I/usr/local/include -I/home/nataly/local/include/ $(OPT)
LFLAGS = -L/usr/local/lib -lm
MODULES = gauss_distr.o

PROGRAMS = gauss_distr.out 

all:$(PROGRAMS)

%.out:%.o $(MODULES)
	$(CC) $^ $(LFLAGS) -o $@
run: 
	./main.out
clean:
		rm -rf *.o *.out 
edit: 
		open *.c *.h makefile &			