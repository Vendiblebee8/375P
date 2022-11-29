TARGET = program4
CC = g++
CFLAGS = -Wall -Wextra -g

all: $(TARGET)

$(TARGET): main.o graph.o
	$(CC) main.o graph.o -o $@

main.o: main.cpp graph.h
	$(CC) $(CFLAGS) -c main.cpp -o $@

graph.o: graph.cpp graph.h
	$(CC) $(CFLAGS) -c graph.cpp -o $@

clean:
	rm -rf *.o $(TARGET)