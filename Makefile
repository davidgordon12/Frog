CC = g++
CCFLAGS = -Iinclude -c

OBJS = bin/tcp_server.o\
       bin/main.o \

all: tcp_server link

tcp_server:
	mkdir -p bin
	$(CC) $(CCFLAGS) src/tcp/main.cpp -o bin/main.o
	$(CC) $(CCFLAGS) src/tcp/server.cpp -o bin/tcp_server.o

link:
	$(CC) $(OBJS) -o frog

clean:
	rm -r bin/*
