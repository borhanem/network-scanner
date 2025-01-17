CC = gcc
CFLAGS = -Wall -g
OBJ = main.o utils.o scanner.o
TARGET = netscan

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: main.c utils.h scanner.h
	$(CC) $(CFLAGS) -c main.c

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

scanner.o: scanner.c scanner.h
	$(CC) $(CFLAGS) -c scanner.c

clean:
	rm -f $(OBJ) $(TARGET)
