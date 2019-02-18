nom_programme=graphe
C_FLAG=-Wall -o3 -g -std=c99 -pedantic
CC=gcc
SRC=$(wildcard *.c)
OBJ=$(SRC:*.c=*.o)
LD=

all:$(nom_programme)

%.o:%.c %.h
	$(CC) $< -c $(C_FLAG)

$(nom_programme):$(OBJ)
	$(CC) $(C_FLAG) $^ -o $@ $(LD)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(nom_programme)

compil: mrproper
	make

