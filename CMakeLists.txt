cmake_minimum_required(VERSION 3.13)
project(NCursesConnectN C)

set(CURSES_USE_NCURSES TRUE)
find_package(Curses REQUIRED)

set(CMAKE_C_STANDARD 11)

add_executable(NCursesConnectN main.c move.c move.h board.c board.h win.c win.h CursorTrakedWindow.c CursorTrakedWindow.h InputValidation.c InputValidation.h)
target_compile_options(NCursesConnectN PRIVATE -Wall -Werror)
target_link_libraries(NCursesConnectN PRIVATE ${CURSES_LIBRARIES})
target_include_directories(NCursesConnectN PRIVATE ${CURSES_INCLUDE_DIRS})

set_target_properties(NCursesConnectN
        PROPERTIES
        OUTPUT_NAME "NCursesConnectN"
        SUFFIX ".out")