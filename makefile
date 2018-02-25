CC = clang++
DEPS = snake.h window.h random_point.h
CLEAN = random_point.h window.o snake.o main.o snake-game snake1.dSYM


.PHONY: clean

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $<

snake: snake.o window.o random_point.o main.o
	$(CC) -o snake-game snake.o window.o random_point.o main.o -std=c++11 -lncurses -stdlib=libc++

clean:
	rm -rf $(CLEAN)
