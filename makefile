CC = clang++
DEPS = snake.h windows.hpp
CLEAN = window.o snake.o main.o snake-game snake1.dSYM


.PHONY: clean

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $<

snake: snake.o window.o main.o
	$(CC) -o snake-game snake.o window.o main.o -lncurses

clean:
	rm -rf $(CLEAN)
