NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SRC = $(addprefix src/, main.c \
	  $(addprefix le_philo/, initializer.c le_philo.c tasks.c) \
	  $(addprefix tools/, cleaner.c error.c ft_atoi.c ft_calloc.c ft_strlen.c tools.c) )
OBJ = $(SRC:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\e[1;32mCompiling from $< to ↴\v$@\e[0m"

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "\e[1;31mHandel the cases 0 philo\e[0m"
	@echo "\e[1;31mwrite func for DIE\e[0m"

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo "All those \`$(foreach i, $(OBJ),\e[1;31m$i\e[0m)\` has been cleaned!"

fclean: clean
	@rm -f $(NAME)
	@echo "\e[1;31mle_$(NAME)\e[0m has been \e[1;41mdeleted\e[0m"

re: fclean all

.PHONY: all clean fclean re
