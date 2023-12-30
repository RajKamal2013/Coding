TARGET = sorting
HEADERS = debug.h
LIBS = -lpthread
CC = gcc
CFLAGS = -g -Wall
OBJECTS = sorting.o
SRC = sorting.c

default: $(TARGET)

$(OBJECTS): $(SRC)  $(HEADERS)
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) -o $(TARGET)

clean:
	-rm -f $(OBJECTS)
	-rm -f $(TARGET)

