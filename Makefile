FLAGS	 = -g -c -Wall
LFLAGS	 =
CC = g++
OBJS = main.o
SOURCE = main.cpp
OUT	= 3n1.exe

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

clean:
	rm -f $(OBJS) $(OUT)

run: $(OUT)
	./$(OUT)