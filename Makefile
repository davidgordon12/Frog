CC = g++
CCFLAGS = -Iinclude

OBJS = bin/main.o \
       bin/server.o \

all: tcp_server tcp_client

tcp_server:
	$(CC) $(CCFLAGS) src/tcp/server.cpp src/main.cpp -o bin/frog

tcp_client:
	$(CC) $(CCFLAGS) src/tcp/client.cpp -o bin/test_client
