CC = g++
CCFLAGS = -Iinclude -c

OBJS = bin/main.o \
       bin/tcp_server.o \
       bin/http_server.o \

all: main tcp_server http_server 

main:
	mkdir -p bin
	$(CC) $(CCFLAGS) src/main.cpp -o bin/main.o

tcp_server:
	mkdir -p bin
	$(CC) $(CCFLAGS) src/tcp/server.cpp -o bin/tcp_server.o

http_server:
	$(CC) $(CCFLAGS) src/http/server.cpp -o bin/http_server.o

link:
	$(CC) $(OBJS) -o frog

tcp_client:
	mkdir -p bin
	$(CC) $(CCFLAGS) src/tcp/client.cpp -o bin/test_client.o