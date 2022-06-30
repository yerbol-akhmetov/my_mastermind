CC = gcc
NAME = my_mastermind
SRC = $(wildcard *.c)
SANITIZE = -g
CFLAGS = -Wall -Wextra -Werror
OBJECTS = $(SRC:.c=.o)
all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(SANITIZE) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJECTS)