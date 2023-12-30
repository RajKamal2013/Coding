TARGET = externalsort
HEADERS = debug.h driver.h
LIBS = -lpthread -lc
CC = gcc
CFLAGS = -g -Wall
OBJECTS = asyncwrite.o driver.o
SRC = asyncwrite.c driver.c

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LIBS)

clean:
	-rm -f $(OBJECTS)
	-rm -f $(TARGET)

