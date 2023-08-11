TARGET1 = tqueue 
TARGET2 = slist
HEADERS1 = debug.h tailQ.h
HEADERS2 = debug.h common.h slist.h
LIBS = -lpthread
CC = gcc
CFLAGS = -g -Wall
OBJECTS1 = tailQ.o tailQTest.o 
OBJECTS2 = common.o slist.o slistTest.o 
SRC1 = tailQ.c tailQTest.c
SRC2 = common.c slist.c slistTest.c

all: $(TARGET1) $(TARGET2)
#all: $(TARGET2)

$(TARGET1): $(OBJECTS1)
	$(CC) $(CFLAGS) -o $(TARGET1) $(OBJECTS1) $(LIBS)
$(TARGET2): $(OBJECTS2)
	$(CC) $(CFLAGS) -o $(TARGET2) $(OBJECTS2) $(LIBS)

clean:
	-rm -f $(OBJECTS1)
	-rm -f $(OBJECTS2)
	-rm -f $(TARGET1)
	-rm -f $(TARGET2)

