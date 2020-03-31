CC=g++
LFLAGS=
CFLAGS=-c -g -Wall -O2
OBJS=server.o digraph.o dijkstra.o serialport.o
PROGS=server

server: server.o digraph.o dijkstra.o serialport.o
	$(CC) server.o digraph.o dijkstra.o serialport.o -o server $(LFLAGS)

digraph: digraph.o
	$(CC) digraph.o -o digraph $(LFLAGS)

serialport: serialport.o
	$(CC) serialport.o -o serialport $(LFLAGS)

server.o: server.cpp
	$(CC) server.cpp -o server.o $(CFLAGS)

digraph.o: digraph.cpp
	$(CC) digraph.cpp -o digraph.o $(CFLAGS)	

dijkstra.o: dijkstra.cpp
	$(CC) dijkstra.cpp -o dijkstra.o $(CFLAGS)

serialport.o: serialport.cpp
	$(CC) serialport.cpp -o serialport.o $(CFLAGS)

clean:
	@rm -f $(PROGS)
	@rm -f $(OBJS)