cmake_minimum_required(VERSION 3.5)

find_package(Curses REQUIRED)

#set(HEADER_FILES include/snake.h include/snake_part.h include/window.h include/random_point.h)

include_directories(${CURSES_INCLUDE_DIR})

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -I../)
endif()

add_executable(snake src/main.cpp src/snake.cpp src/snake_part.cpp src/window.cpp src/random_point.cpp)
target_link_libraries(snake ${CURSES_LIBRARIES})

