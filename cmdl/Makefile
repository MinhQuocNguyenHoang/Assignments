CC = gcc

obj = unit_test.o cmdl.o

all: $(obj)
	$(CC) $(obj) -o cmdl_test

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f *.o cmdl_test