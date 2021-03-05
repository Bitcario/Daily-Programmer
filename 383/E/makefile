CC = gcc
NAME = nm.out
CFLAGS = -std=c99 -Wall -Wextra
DEPS = 383_E.c 
OBJ = 383_E.o 

CC2 = g++
NAME2 = bonus2.out
CFLAGS2 = -std=c++11 -Wall -Wextra
DEPS2 = 383_E_bonus_2.cpp
OBJ2 = 383_E_bonus_2.o

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME2): $(OBJ2)
	$(CC2) -o $@ $^ $(CFLAGS2)

%.o: %.cpp $(DEPS2)
	$(CC2) -c -o $@ $< $(CFLAGS2)

all: $(NAME) $(NAME2) 

run:
	./$(NAME) && ./$(NAME2)
clean:
	rm *.out *.o
