CC = clang++
DEPS = snake_part.h snake.h window.h random_point.h
CLEAN = random_point.o window.o snake_part.o snake.o main.o snake-game snake1.dSYM


.PHONY: clean

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $<

snake: snake_part.o snake.o window.o random_point.o main.o
	$(CC) -g -o snake-game snake_part.o snake.o window.o random_point.o main.o -std=c++11 -lncurses

clean:
	rm -rf $(CLEAN)
