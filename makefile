CC = clang++
DEPS = src/snake_part.h src/snake.h src/window.h src/random_point.h
CLEAN = snake-game snake1.dSYM
OBJ = src/snake_part.o src/window.o src/snake.o src/random_point.o src/main.o
LIB = -lncurses -lpthread
FLAGS = -Wall -Wpedantic -Weverything

.PHONY: clean

%.o: src/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(FLAGS)

snake: $(OBJ)
	$(CC) $(OBJ) -std=c++11 $(LIB) -o snake-game $(FLAGS)

clean:
	rm -rf src/*.o $(CLEAN)
