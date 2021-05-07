CC		= g++
NVCC		= nvcc
GCC_OPTIONS	= -std=c++17 -Wall --pedantic-error

LDGLAGS		= # 動的リンクファイル *.so
LIBS		= # 静的リンクファイル *.a
INCLUDE		= -I./include

PROGRAM = main

all : $(PROGRAM)

main : main.cpp
	$(CC) $(GCC_OPTIONS) $^ -o $@

rum : ./main

clean :
	rm -f $(PROGRAM)
	rm -f *.o

.PHONY :	run clean
