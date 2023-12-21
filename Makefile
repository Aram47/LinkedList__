G++ = g++
FILES = main.cpp list.cpp
EXE = List
DEL = rm

all:
	$(G++) $(FILES) -o $(EXE)

del:
	$(DEL) -r $(EXE)