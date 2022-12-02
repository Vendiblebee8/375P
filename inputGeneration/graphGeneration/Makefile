TARGET = generate
CC = g++
CFLAGS = -Wall -Wextra -g

all: $(TARGET)

$(TARGET): generate.o 
	$(CC) generate.o -o $@

generate.o: generate.cpp 
	$(CC) $(CFLAGS) -c generate.cpp -o $@


clean:
	rm -rf *.o $(TARGET)