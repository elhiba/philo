NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SRC = $(wildcard src/*.c src/tools/*.c)
OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "\e[1;31mBefore You push fix the wildcard!\e[0m"

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
