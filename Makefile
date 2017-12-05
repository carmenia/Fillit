NAME = Fillit

SRCS= main.c			\

LIBFT = libft

SRCO = $(SRCS:.c=.o)

INCL = -I ./

.PHONY: all clean fclean re

all: $(NAME)

$(LIBFT):
	@make -c $(@)

$(NAME): $(LIBFT)
	gcc -Wall -Wextra -Werror -o $(NAME) $(LIBFT) $(INCL)

clean:
	rm -f $(SRCO)
	@make -c $(LIBFT) clean

flcean: clean
	rm -f $(NAME)

re: fclean all
