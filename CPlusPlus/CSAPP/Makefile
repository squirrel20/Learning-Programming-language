
CC = gcc
CXX = g++

CFLAGS = -g
CXXFLAGS += $(CFLAGS)

OBJS = $(patsubst %.c,%.o,$(wildcard *.c))

INC += -I./

#LIB += -lz -lrt

BIN = test

.c.o:
	$(CC) $(CFLAGS) $(INC) -c $^


.cpp.o:
	$(CXX) $(CXXFLAGS) $(INC) -c $^


all: $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJS) #$(LIB)
	./$(BIN)

clean:
	rm *.o $(BIN)
