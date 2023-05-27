CC = gcc
CFLAGS = -Wall -Wextra -pedantic
TARGET = main

all: $(TARGET)

$(TARGET): $(TARGET).o
	$(CXX) $(CFLAGS) -o $(TARGET) $(TARGET).o

clean:
	rm -f $(TARGET)
