NAME = philo

CC = cc
CFLAGS = -g3 #-Wall -Wextra -Werror 

SRC = $(wildcard src/*.c tools/*.c)
OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "\e[1;31mbefore You push fix the wildcard!\e[0m"
	@echo "\e[1;31mNO_FLAGS!\e[0m"

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
