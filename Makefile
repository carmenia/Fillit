
/*
** essayer methode: %.o: %.c \n gcc -Flag -c $(INCL) ^$
*/


NAME = Fillit

SRCS= main.c				\
	  ft_file_reader.c		\
	  ft_tetromino_detect.c	\

.PHONY: all clean fclean re

LIBFT = libft

SRCO = $(SRCS:.c=.o)

INCL = -I ./

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
