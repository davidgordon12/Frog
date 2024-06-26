all: server client

server:
	g++ src/tcp/listener.cpp

client:
	g++ src/tcp/client.cpp
