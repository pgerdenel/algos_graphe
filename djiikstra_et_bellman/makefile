PGM=d_and_b 
C_FLAG=-Wall -o3 -g -std=c99 -pedantic
CC=gcc
SRC=$(wildcard *.c)
OBJ=$(SRC:*.c=*.o)
LD=

all:$(PGM)

%.o:%.c %.h
	$(CC) $< -c $(C_FLAG)

$(PGM):$(OBJ)
	$(CC) $(C_FLAG) $^ -o $@ $(LD)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(PGM)

compil: mrproper
	make

