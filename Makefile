TARGET = program4
CC = g++
CFLAGS = -Wall -Wextra -g

all: $(TARGET)

$(TARGET): main.o graph.o graphmatrix.o
	$(CC) main.o graph.o graphmatrix.o -o $@

main.o: main.cpp graph.h graphmatrix.h
	$(CC) $(CFLAGS) -c main.cpp -o $@

graph.o: graph.cpp graph.h
	$(CC) $(CFLAGS) -c graph.cpp -o $@

graphmatrix.o: graphmatrix.cpp graphmatrix.h
	$(CC) $(CFLAGS) -c graphmatrix.cpp -o $@

clean:
	rm -rf *.o $(TARGET)