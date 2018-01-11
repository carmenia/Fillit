
NAME = Fillit

SRC=	main.c					\
		ft_mino_reader.c		\
		ft_create_and_free.c	\
		ft_solve.c				\
		ft_mapper_functions.c	\

.PHONY: all clean fclean re libft
OBJ = ${SRC:.c=.o}

CC = clang

CFLAGS = -Wall -Wextra -Werror -I Libft 

LDFLAGS = -L Libft -l ft

all: $(NAME)

$(NAME): libft $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(OBJ)

libft:
	Make -C Libft

clean:
	rm -rf $(OBJ)
	Make -C Libft clean

fclean: clean
	rm -rf $(NAME)
	Make -C Libft fclean

re: fclean all
	Make -C Libft re

