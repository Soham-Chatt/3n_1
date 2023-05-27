CC = gcc
CFLAGS = -Wall -Wextra -pedantic
TARGET = main

all: $(TARGET)

run: $(TARGET)
	./$(TARGET)

$(TARGET): $(TARGET).o
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).o

clean:
	rm -f $(TARGET) $(TARGET).o
