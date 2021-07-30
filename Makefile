CC := g++

PROG := main
OBJ := main.o game.o maze.o player.o

all: $(OBJ) $(PROG) clean

$(PROG) : $(OBJ)
	$(CC) -o $@ $^

.cpp.o:
	$(CC) -c $^


.PHONY: clean
clean:
	rm -f $(OBJ)
