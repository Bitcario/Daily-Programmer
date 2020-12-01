CC = gcc
NAME = nm.out
CFGLAGS= -std=c99 -Wall -Wextra
DEPS = 383_E.c 
OBJ = 383_E.o 

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFGLAGS)

run:
	./$(NAME)
runin:
	./$(NAME) < input
clean:
	rm $(NAME) $(OBJ)
