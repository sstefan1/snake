CC = clang++
DEPS = snake_part.h snake.h window.h random_point.h
CLEAN = snake-game snake1.dSYM
OBJ = snake_part.o window.o snake.o random_point.o main.o
LIB = -lncurses -lpthread

.PHONY: clean

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $<

snake: $(OBJ)
	$(CC) $(OBJ) -std=c++11 $(LIB) -o snake-game

clean:
	rm -rf *.o $(CLEAN)
