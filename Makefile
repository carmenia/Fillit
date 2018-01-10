
NAME = Fillit

SRCS=	main.c					\
		ft_mino_reader.c		\
		ft_create_and_free.c	\

.PHONY: all clean fclean re

LIBFT = libft

SRCO = $(SRCS:.c=.o)

INCL = -I

all: $(NAME)

$(LIBFT):
	@make -c $(@)

$(NAME): $(LIBFT)
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRCS) $(INCL) $(LIBFT)

clean:
	rm -f $(SRCO)
	@make -c $(LIBFT) clean

flcean: clean
	rm -f $(NAME)

re: fclean all
