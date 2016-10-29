
all:map pointer

%: %.o
	gcc -o % %.o

%.o: %.c
	gcc -c %.c

clean:
	rm -f map pointer
	rm -f *.o
	rm -f *~
