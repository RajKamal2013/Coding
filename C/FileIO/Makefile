TARGET = asyncio
HEADERS = debug.h asyncIo.h
LIBS = -lrt
CC = gcc
CFLAGS = -g -Wall
OBJECTS = asyncIo.o testAsync.o
SRC = asyncIo.c testAsync.c

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LIBS)

clean:
	-rm -f $(OBJECTS)
	-rm -f $(TARGET)

