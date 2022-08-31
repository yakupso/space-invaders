CC=g++
FLAGS=-Werror -Wextra -Wall -lncurses
CFLAGS=-c -Werror -Wextra -Wall
BUILD_PATH=../build

all: alien_invasion

alien_invasion: field.o alien.o ship.o bullet.o
	$(CC) $(FLAGS) main.cpp $(BUILD_PATH)/field.o $(BUILD_PATH)/alien.o $(BUILD_PATH)/ship.o $(BUILD_PATH)/bullet.o -o $(BUILD_PATH)/alien_invasion

field.o:
	$(CC) $(CFLAGS) field.cpp -o $(BUILD_PATH)/field.o

alien.o:
	$(CC) $(CFLAGS) alien.cpp -o $(BUILD_PATH)/alien.o

ship.o:
	$(CC) $(CFLAGS) ship.cpp -o $(BUILD_PATH)/ship.o

bullet.o:
	$(CC) $(CFLAGS) bullet.cpp -o $(BUILD_PATH)/bullet.o

clean:
	rm $(BUILD_PATH)/*

rebuild: clean all