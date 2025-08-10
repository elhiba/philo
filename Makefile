NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SRC = $(addprefix src/, main.c \
	  $(addprefix le_philo/, initializer.c le_philo.c tasks.c) \
	  $(addprefix tools/, cleaner.c error.c ft_atoi.c ft_calloc.c ft_strlen.c tools.c) )
OBJ = $(SRC:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\e[1;32mCompiling from $< to $@\e[0m"

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $@

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo "All those object files:\n\`$(foreach i, $(OBJ),\e[1;31m$i\e[0m\n)\` has been cleaned!"

fclean: clean
	@rm -f $(NAME)
	@echo "\e[1;31mle_$(NAME)\e[0m has been \e[1;41mdeleted\e[0m!"

re: fclean all

.PHONY: all clean fclean re
.SECONDARY:
