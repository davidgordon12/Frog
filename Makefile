CC = g++
CCFLAGS = -I include -c

tcp:
	$(CC) $(CCFLAGS) src/tcp/server.cpp -o bin/server.o
	$(CC) $(CCFLAGS) src/tcp/client.cpp -o bin/client.o
	$(CC) $(CCFLAGS) src/main.cpp -o bin/main.o
	$(CC) bin/*.o -o frog

